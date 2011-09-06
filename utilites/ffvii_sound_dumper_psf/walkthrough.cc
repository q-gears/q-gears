#include <string>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include "walkthrough.hh"



using namespace boost::filesystem;



bool walkthrough(path a_path, void (*f_cb)(void *, path), void *a_data)
{
	bool result = false;

	if(exists(a_path) && is_directory(a_path))
	{
		directory_iterator it_end;

		for(directory_iterator it(a_path); it != it_end; ++it)
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
