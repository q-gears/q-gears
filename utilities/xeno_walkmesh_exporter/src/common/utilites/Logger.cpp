// $Id: Logger.cpp 147 2007-02-24 06:13:17Z super_gb $

#include "Logger.h"
#include "../filesystem/RealFileSystem.h"
#include <iostream>
#include <stdarg.h>
#include <time.h>



Logger* LOGGER = NULL; // global and accessable from anywhere in our program



const RString Logger::m_MessageStrings[4] = {"(II)", "(WW)", "(EE)", "(--)"};



Logger::Logger(const RString& logFileName, bool outputToConsole, bool outputToFile):
    m_LogFile(logFileName),
    m_ConsoleOutput(outputToConsole),
    m_FileOutput(outputToFile)
{
    REALFILESYSTEM->RemoveFile(m_LogFile);
}



Logger::~Logger(void)
{
}



void Logger::Log(MessageType logType, const char* logText, ...)
{
    if (m_ConsoleOutput || m_FileOutput)
    {
        RString buf;
        // Use a temporary buffer to fill in the variables
        va_list ap;
        va_start(ap, logText);
        buf.FormatV(logText, ap);
        va_end(ap);

        // Get the current system time
        time_t t;
        time(&t);

        // Print the log entry
        RString string;
        string.Format("[%02d:%02d:%02d] %s %s\n", (int)(((t / 60) / 60) % 24),
            (int)((t / 60) % 60), (int)(t % 60),
            m_MessageStrings[logType].c_str(), buf.c_str());
        if (m_ConsoleOutput)
        {
            std::cout << string;
        }

        if (m_FileOutput)
        {
            REALFILESYSTEM->WriteFile(m_LogFile, string.c_str(), string.size());
        }
    }
}
