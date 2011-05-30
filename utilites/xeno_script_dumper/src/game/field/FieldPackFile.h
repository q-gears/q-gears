#ifndef FIELD_PACK_FILE_h
#define FIELD_PACK_FILE_h

#include "../../common/utilites/StdString.h"

#include "../filesystem/File.h"



class FieldPackFile : public File
{
public:
// LIFECYCLE

    /**
     * @brief A constructor.
     *
     * Read file from given path into memory.
     * @param file - path to file that we want to open.
     */
    explicit FieldPackFile(const RString& file);

    /**
     * @brief A constructor.
     *
     * Create completle copy of given file.
     * @param pFile - object that we want to copy.
     */
    explicit FieldPackFile(File* pFile);

    /**
     * @brief A constructor.
     *
     * Create partitial copy of given file.
     * @param pFile  - object that we want to copy.
     * @param offset - offset from where we want to copy data.
     * @param length - size of data that we want ot copy.
     */
    FieldPackFile(File* pFile, const u32& offset, const u32& length);

    /**
     * @brief A constructor.
     *
     * Create partitial copy of given buffer.
     * @param pBuffer - buffer from which we want to create new file.
     * @param offset  - offset from where we want to copy data.
     * @param length  - size of data that we want ot copy.
     */
    FieldPackFile(u8* pBuffer, const u32& offset, const u32& length);

    /**
     * @brief A destructor.
     */
    virtual ~FieldPackFile(void);

// OPERATIONS

    File* Extract(u32 file_number);
};



#endif // FIELD_PACK_FILE_h
