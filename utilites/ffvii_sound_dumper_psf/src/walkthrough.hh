#ifndef WALKTHROUGH_HH__
#define WALKTHROUGH_HH__



#include <boost/filesystem/path.hpp>



bool walkthrough(boost::filesystem::path a_path, void (*f_cb)(void *, boost::filesystem::path), void *a_data);



#endif
