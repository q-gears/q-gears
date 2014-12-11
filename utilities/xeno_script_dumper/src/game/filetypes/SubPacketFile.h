// $Id: SubPacketFile.h 93 2006-11-12 13:49:02Z einherjar $

/**
 * @brief Class for subpacket in packet file archives.
 */

#ifndef SUB_PACKET_FILE_h
#define SUB_PACKET_FILE_h

#include "../../common/utilites/StdString.h"

#include "PacketFile.h"



class SubPacketFile : public PacketFile
{
public:
// LIFECYCLE

    /**
     * @brief A constructor.
     *
     * Read file from given path into memory.
     * @param file - path to file that we want to open.
     */
    explicit SubPacketFile(const RString& file);

    /**
     * @brief A constructor.
     *
     * Create completle copy of given file.
     * @param pFile - object that we want to copy.
     */
    explicit SubPacketFile(File* pFile);

    /**
     * @brief A constructor.
     *
     * Create partitial copy of given file.
     * @param pFile  - object that we want to copy.
     * @param offset - offset from where we want to copy data.
     * @param length - size of data that we want ot copy.
     */
    SubPacketFile(File* pFile, const u32& offset, const u32& length);

    /**
     * @brief A constructor.
     *
     * Create partitial copy of given buffer.
     * @param pBuffer - buffer from which we want to create new file.
     * @param offset  - offset from where we want to copy data.
     * @param length  - size of data that we want ot copy.
     */
    SubPacketFile(u8* pBuffer, const u32& offset, const u32& length);

    /**
     * @brief A destructor.
     */
    virtual ~SubPacketFile(void);

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
};



#endif // SUB_PACKET_FILE_h
