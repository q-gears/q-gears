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



#include "OgreLogManager.h"

#include "MediaEngine.h"



using namespace std;



const string MediaEngine::m_DEFAULT_PATH("");


const bool MediaEngine::AddRecord(const int arg_id, const string &arg_filename)
{
	bool result;

	if(GetRecord(arg_id) == m_RecordDB.end())
	{
		Record record = {arg_id, arg_filename};
		m_RecordDB.push_back(record);
		result = true;
	}
	else
		result = false;

	return result;
}

const bool MediaEngine::IsRecordAdded(const int arg_id)
{
	return GetRecord(arg_id) != m_RecordDB.end();
}

const bool MediaEngine::RemoveRecord(const int arg_id)
{
	bool result;

	list<Record>::iterator it = GetRecord(arg_id);
	if(it != m_RecordDB.end())
	{
		m_RecordDB.erase(it);
		result = true;
	}
	else
		result = false;

	return result;
}

const string &MediaEngine::GetRecordPath(const int arg_id)
{
	list<Record>::iterator record = GetRecord(arg_id);
	return record == m_RecordDB.end() ? m_DEFAULT_PATH : record->path;
}


list<MediaEngine::Record>::iterator MediaEngine::GetRecord(const int arg_id)
{
	list<Record>::iterator result = m_RecordDB.end();

	for(list<Record>::iterator it = m_RecordDB.begin();
			it != m_RecordDB.end(); ++it)
	{
		if(it->id == arg_id)
		{
			result = it;
			break;
		}
	}

	return result;
}


void MediaEngine::SetLogPrefix(const string &arg_prefix)
{
	m_LogPrefix = arg_prefix;
}


void MediaEngine::Log(const string &arg_message)
{
	Ogre::LogManager::getSingleton().logMessage(m_LogPrefix + arg_message);
}
