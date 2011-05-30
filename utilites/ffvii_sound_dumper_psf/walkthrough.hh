#ifndef WALKTHROUGH_HH__
#define WALKTHROUGH_HH__



#include <string>



bool walkthrough(std::string a_path, void (*f_cb)(void *, std::string), void *a_data);



#endif
