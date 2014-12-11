// $Id: File.h 105 2006-12-02 00:07:47Z einherjar $

/**
 * @brief Base class for all file loaders.
 */

#ifndef FILE_h
#define FILE_h

#include "../../common/TypeDefine.h"
#include "../../common/utilites/NoCopy.h"
#include "../../common/utilites/StdString.h"

class FileSystem;


class File : public NoCopy<File>
{
public:
// LIFECYCLE

    /**
     * @brief A constructor.
     *
     * Read file from given path into memory.
     * @param fs - file system to use to access file
     * @param file - path to file that we want to open.
     */
    explicit File(FileSystem &fs, const RString& file);

    /**
     * @brief A constructor.
     *
     * Create completle copy of given file.
     * @param pFile - object that we want to copy.
     */
    explicit File(File* pFile);

    /**
     * @brief A constructor.
     *
     * Create partitial copy of given file.
     * @param pFile  - object that we want to copy.
     * @param offset - offset from where we want to copy data.
     * @param length - size of data that we want ot copy.
     */
    File(File* pFile, const u32& offset, const u32& length);

    /**
     * @brief A constructor.
     *
     * Create partitial copy of given buffer.
     * @param pBuffer - buffer from which we want to create new file.
     * @param offset  - offset from where we want to copy data.
     * @param length  - size of data that we want ot copy.
     */
    File(u8* pBuffer, const u32& offset, const u32& length);

    /**
     * @brief A destructor.
     */
    virtual ~File(void);

// OPERATIONS

    /**
     * @brief Write file buffer.
     *
     * Write file buffer into file with given name.
     * If file already exist it will be overritten.
     * @param file - path to file that we want to create.
     */
    void WriteFile(const RString& file) const;

// ACCESS

    /**
     * @brief Get name.
     *
     * Get original name of the file.
     * @return name of file.
     */
    const RString& GetFileName(void) const;

    /**
     * @brief Get file size.
     *
     * Get size of buffer. Can differs from original file.
     * @return size of buffer.
     */
    const u32& GetFileSize(void) const;

    /**
     * @brief Get file buffer.
     *
     * Fill given buffer with part of file.
     * @param pBuffer - buffer to copy to
     * @param start   - offset from where we want to copy data
     * @param length  - size of data that we want ot copy.
     */
    void GetFileBuffer(u8* pBuffer, const u32& start, const u32& length) const;

    /**
     * @brief Get 1 byte.
     *
     * Utility function that extract data with given offset from buffer
     * @param offset - offset to 1 byte that we want to get.
     * @return 1 byte from file buffer with given offset.
     */
    const u8  GetU8(const u32& offset) const;

    /**
     * @brief Get 2 bytes.
     *
     * Utility function that extract data with given offset from buffer
     * @param offset - offset to 2 bytes that we want to get.
     * @return 2 bytes from file buffer with given offset.
     */
    const u16 GetU16LE(const u32& offset) const;

    /**
     * @brief Get 4 bytes.
     *
     * Utility function that extract data with given offset from buffer
     * @param offset - offset to 4 bytes that we want to get.
     * @return 4 bytes from file buffer with given offset.
     */
    const u32 GetU32LE(const u32& offset) const;

protected:
    RString mFileName;   /**< @brief name of file       */
    u8*     mpBuffer;    /**< @brief loaded file buffer */
    u32     mBufferSize; /**< @brief size of buffer     */
};

#endif // !FILE_h
