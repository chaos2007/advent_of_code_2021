#ifndef __FILE_UTILS_H__
#define __FILE_UTILS_H__

#include <vector>
#include <string>

using namespace std;

bool read_as_list_of_strings(string filename, vector<string> &lines);
bool read_as_list_of_list_of_strings(string filename, vector<vector<string>> &lines);


#endif
