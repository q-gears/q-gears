// $Id: LzsFile.h 93 2006-11-12 13:49:02Z einherjar $

/**
 * @brief Class for LZS file archives.
 */

#ifndef LZS_FILE_h
#define LZS_FILE_h

#include "../filesystem/File.h"

#include "../../common/utilites/StdString.h"



class LzsFile : public File
{
public:
// LIFECYCLE

    /**
     * @brief A constructor.
     *
     * Read file from given path into memory.
     * @note after creation in buffer stored unarchived file.
     * @param file - path to file that we want to open.
     */
    explicit LzsFile(const RString& file);

    /**
     * @brief A constructor.
     *
     * Create completle copy of given file.
     * @note after creation in buffer stored unarchived file.
     * @param pFile - object that we want to copy.
     */
    explicit LzsFile(File* pFile);

    /**
     * @brief A constructor.
     *
     * Create partitial copy of given file.
     * @note after creation in buffer stored unarchived file.
     * @param pFile  - object that we want to copy.
     * @param offset - offset from where we want to copy data.
     * @param length - size of data that we want ot copy.
     */
    LzsFile(File* pFile, const u32& offset, const u32& length);

    /**
     * @brief A constructor.
     *
     * Create partitial copy of given buffer.
     * @note after creation in buffer stored unarchived file.
     * @param pBuffer - buffer from which we want to create new file.
     * @param offset  - offset from where we want to copy data.
     * @param length  - size of data that we want ot copy.
     */
    LzsFile(u8* pBuffer, const u32& offset, const u32& length);

    /**
     * @brief A destructor.
     */
    virtual ~LzsFile(void);

private:
// OPERATIONS

    /**
     * @brief Extract LZS into inner buffer.
     *
     * Extract LZS into buffer and then replace inner bufer with extracted one.
     * I calls automaticly when object is constructed.
     */
    void ExtractLzs(void);
};



#endif // LZS_FILE_h
