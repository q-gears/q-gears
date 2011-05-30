// $Id: Logger.cpp 147 2007-02-24 06:13:17Z super_gb $

#include "Logger.h"
#include "../filesystem/RealFileSystem.h"
#include <iostream>
#include <stdarg.h>



Logger* LOGGER = NULL; // global and accessable from anywhere in our program



Logger::Logger(const RString& logFileName):
    m_LogFile(logFileName)
{
    REALFILESYSTEM->RemoveFile(m_LogFile);
}



Logger::~Logger(void)
{
}



void Logger::Log(const char* logText, ...)
{
    RString buf;
    // Use a temporary buffer to fill in the variables
    va_list ap;
    va_start(ap, logText);
    buf.FormatV(logText, ap);
    va_end(ap);

    // Print the log entry
    RString string;
    string.Format("%s", buf.c_str());

    REALFILESYSTEM->WriteFile(m_LogFile, string.c_str(), string.size());
}
