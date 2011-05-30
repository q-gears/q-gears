#ifndef ARCHIVE_FILE_h
#define ARCHIVE_FILE_h

#include "../../common/utilites/StdString.h"

#include "../filesystem/File.h"



class ArchiveFile : public File
{
public:
// LIFECYCLE

    /**
     * @brief A constructor.
     *
     * Read file from given path into memory.
     * @param file - path to file that we want to open.
     */
    explicit ArchiveFile(const RString& file);

    /**
     * @brief A constructor.
     *
     * Create completle copy of given file.
     * @param pFile - object that we want to copy.
     */
    explicit ArchiveFile(File* pFile);

    /**
     * @brief A constructor.
     *
     * Create partitial copy of given file.
     * @param pFile  - object that we want to copy.
     * @param offset - offset from where we want to copy data.
     * @param length - size of data that we want ot copy.
     */
    ArchiveFile(File* pFile, const u32& offset, const u32& length);

    /**
     * @brief A constructor.
     *
     * Create partitial copy of given buffer.
     * @param pBuffer - buffer from which we want to create new file.
     * @param offset  - offset from where we want to copy data.
     * @param length  - size of data that we want ot copy.
     */
    ArchiveFile(u8* pBuffer, const u32& offset, const u32& length);

    /**
     * @brief A destructor.
     */
    virtual ~ArchiveFile(void);

private:
    void Extract(void);
};



#endif // ARCHIVE_FILE_h
