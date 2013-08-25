// $Id: BinGZipFile.h 93 2006-11-12 13:49:02Z einherjar $

/**
 * @brief Class for BinGZip file archives.
 */

#ifndef BIN_G_ZIP_FILE_h
#define BIN_G_ZIP_FILE_h

#include "../filesystem/File.h"

#include "../../common/utilites/StdString.h"



class BinGZipFile : public File
{
public:
// LIFECYCLE

    /**
     * @brief A constructor.
     *
     * Read file from given path into memory.
     * @param file - path to file that we want to open.
     */
    explicit BinGZipFile(const RString& file);

    /**
     * @brief A constructor.
     *
     * Create completle copy of given file.
     * @param pFile - object that we want to copy.
     */
    explicit BinGZipFile(File* pFile);

    /**
     * @brief A constructor.
     *
     * Create partitial copy of given file.
     * @param pFile  - object that we want to copy.
     * @param offset - offset from where we want to copy data.
     * @param length - size of data that we want ot copy.
     */
    BinGZipFile(File* pFile, const u32& offset, const u32& length);

    /**
     * @brief A constructor.
     *
     * Create partitial copy of given buffer.
     * @param pBuffer - buffer from which we want to create new file.
     * @param offset  - offset from where we want to copy data.
     * @param length  - size of data that we want ot copy.
     */
    BinGZipFile(u8* pBuffer, const u32& offset, const u32& length);

    /**
     * @brief A destructor.
     */
    virtual ~BinGZipFile(void);

// OPERATIONS

    /**
     * @brief Extract ungzipped part of archive.
     *
     * Extract ungzipped part of archive and create new file object.
     * @return pointer to new file object.
     * If some error is occured then NULL pointer will be returned.
     * @warning returned pointer must be deleted to prevent memory leak.
     * @param fileNumber - number of file you want to extract.
     * If value is greater than real number of file in archive then NULL pointer is returned.
     */
    File* ExtractGZip(const u32& fileNumber);

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

    /**
     * @brief Get offset of file in BinGZip archive.
     *
     * Search file for file offset.
     * @return offset to file. If fileNumber greater than real number of files in archive, then zero is returned.
     */
    u32 InnerGetFileOffset(const u32& fileNumber);

private:
    u32 mNumberOfFiles; /**< @brief number of files in archive */
};



#endif // BIN_G_ZIP_FILE_h
