// $Id: Logger.h 147 2007-02-24 06:13:17Z super_gb $

#ifndef LOGGER_H
#define LOGGER_H

// The Log Class : Useful to write debug or info messages

#include "NoCopy.h"
#include "StdString.h"



enum MessageType
{
    LOGGER_INFO,
    LOGGER_WARNING,
    LOGGER_ERROR,
    LOGGER_OTHER
};



class Logger : public NoCopy<Logger>
{
public:
    // Constructor, opens log file for writing.
    explicit Logger(const RString& logFileName, bool outputToConsole, bool outputToFile);

    // Destructor, closes log file.
    virtual ~Logger(void);

    // Enters a message in the log. The message will be timestamped.
    void     Log(MessageType logType,const char* logText, ...);

private:
    RString              m_LogFile;
    static const RString m_MessageStrings[4];

    bool                 m_ConsoleOutput;
    bool                 m_FileOutput;
};



// Visible from every part of programm
extern Logger *LOGGER;



#endif // LOGGER_H

