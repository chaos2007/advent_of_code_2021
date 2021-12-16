#include "file_utils.h"

#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool read_as_list_of_strings(string filename, vector<string> &lines) {
  ifstream infile(filename);
  if (!infile) {
    cerr << "*****Error opening file " << filename << endl;
    return false;
  }
  string line;
  while (getline(infile, line)) {
    lines.push_back(line);
  }
  infile.close();
  return true;
}

bool read_as_list_of_list_of_strings(string filename,
                                     vector<vector<string>> &lines) {
  char delim[] = " ";
  ifstream infile(filename);
  if (!infile) {
    cerr << "*****Error opening file " << filename << endl;
    return false;
  }
  string line;
  while (getline(infile, line)) {
    vector<string> out;
    char *token = strtok(const_cast<char *>(line.c_str()), delim);
    while (token != nullptr) {
      out.push_back(std::string(token));
      token = strtok(nullptr, delim);
    }
    lines.push_back(out);
  }
  infile.close();
  return true;
}
