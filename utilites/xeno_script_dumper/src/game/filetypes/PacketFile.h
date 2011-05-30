// $Id: PacketFile.h 93 2006-11-12 13:49:02Z einherjar $

/**
 * @brief Class for packet file archives.
 */

#ifndef PACKET_FILE_h
#define PACKET_FILE_h

#include "../../common/utilites/StdString.h"

#include "../filesystem/File.h"



class PacketFile : public File
{
public:
// LIFECYCLE

    /**
     * @brief A constructor.
     *
     * Read file from given path into memory.
     * @param file - path to file that we want to open.
     */
    explicit PacketFile(const RString& file);

    /**
     * @brief A constructor.
     *
     * Create completle copy of given file.
     * @param pFile - object that we want to copy.
     */
    explicit PacketFile(File* pFile);

    /**
     * @brief A constructor.
     *
     * Create partitial copy of given file.
     * @param pFile  - object that we want to copy.
     * @param offset - offset from where we want to copy data.
     * @param length - size of data that we want ot copy.
     */
    PacketFile(File* pFile, const u32& offset, const u32& length);

    /**
     * @brief A constructor.
     *
     * Create partitial copy of given buffer.
     * @param pBuffer - buffer from which we want to create new file.
     * @param offset  - offset from where we want to copy data.
     * @param length  - size of data that we want ot copy.
     */
    PacketFile(u8* pBuffer, const u32& offset, const u32& length);

    /**
     * @brief A destructor.
     */
    virtual ~PacketFile(void);

// OPERATIONS

    /**
     * @brief Extract part of archive.
     *
     * Extract part of archive and create new file object.
     * @return pointer to new file object.
     * If some error is occured then NULL pointer will be returned.
     * @warning returned pointer must be deleted to prevent memory leak.
     * @param fileNumber - number of file you want to extract.
     * If value is greater than real number of file in archive then NULL pointer is returned.
     */
    virtual File* ExtractFile(const u32& fileNumber);

// ACCESS

    /**
     * @brief Get number of files in archive.
     *
     * @return number of files in archive.
     */
    const u32& GetNumberOfFiles(void);

private:
// OPERATIONS

    /**
     * @brief Set mNumberOfFiles attribute.
     *
     * Search file for file numbers and set mNumberOfFiles attribute.
     */
    void InnerGetNumberOfFiles(void);

private:
    u32 mNumberOfFiles; /**< @brief number of files in archive */
};



#endif // PACKET_FILE_h
