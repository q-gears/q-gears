// $Id: Logger.h 147 2007-02-24 06:13:17Z super_gb $

#ifndef LOGGER_H
#define LOGGER_H

// The Log Class : Useful to write debug or info messages

#include "NoCopy.h"
#include "StdString.h"



class Logger : public NoCopy<Logger>
{
public:
    // Constructor, opens log file for writing.
    explicit Logger(const RString& logFileName);

    // Destructor, closes log file.
    virtual ~Logger(void);

    // Enters a message in the log. The message will be timestamped.
    void     Log(const char* logText, ...);

private:
    RString              m_LogFile;
};



// Visible from every part of programm
extern Logger *LOGGER;



#endif // LOGGER_H

