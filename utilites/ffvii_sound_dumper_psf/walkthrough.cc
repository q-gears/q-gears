#include <string>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include "walkthrough.hh"



using namespace boost::filesystem;



bool walkthrough(std::string a_path, void (*f_cb)(void *, std::string), void *a_data)
{
	bool result = false;

	path dpath(a_path);

	if(exists(dpath) && is_directory(dpath))
	{
		directory_iterator it_end;
		
		for(directory_iterator it(dpath); it != it_end; ++it)
		{
			if(is_directory(it->status()))
			{
				walkthrough(it->path().string(), f_cb, a_data);
			}
			else if(is_regular_file(it->status()))
			{
				f_cb(a_data, it->path().string());
			}
		}

		result = true;
	}

	return result;
}
