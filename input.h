#ifndef INPUT
#define INPUT

#include <iostream>
#include <vector> 
#include <string.h>
#include <string>
#include <fstream>
#include "TankList.h"
#include "engine.h"

using namespace std;
class Input
{
public:
	void readInputs(string filename);
	bool isStringNeedValue(string str);
	void tokenize(std::string const& str, const char delim, std::vector<std::string>& out);
	string remove_spaces(const string& s);
};
#endif