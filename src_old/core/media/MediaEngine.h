/*
	This file is part of Q-Gears.

	Copyright 2008,2009 Gennadiy Brich

	Q-Gears is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Q-Gears is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Q-Gears.  If not, see <http://www.gnu.org/licenses/>.
*/



#ifndef MEDIA_ENGINE_HH__
#define MEDIA_ENGINE_HH__



#include <string>
#include <list>



class MediaEngine
{
private:
	// logging
	std::string m_LogPrefix;
	
	// db management
	struct Record
	{
		int id;
		std::string path;
	};

	static const std::string m_DEFAULT_PATH;
	std::list<Record> m_RecordDB;

	std::list<Record>::iterator GetRecord(const int arg_id);
	
protected:
	typedef uint32_t Handle;

	enum
	{
		INVALID_HANDLE = 0
	};

	// logging
	void SetLogPrefix(const std::string &arg_prefix);
	void Log(const std::string &arg_message);
	
public:
	const bool AddRecord(const int arg_id, const std::string &arg_filename);
	const bool IsRecordAdded(const int arg_id);
	const bool RemoveRecord(const int arg_id);
	const std::string &GetRecordPath(const int arg_id);
};



#endif
