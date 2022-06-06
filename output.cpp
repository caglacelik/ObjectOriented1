#include "output.h"#include <iostream>#include <fstream>void Output::writeDatas(std::string fileName) {	std::ofstream file(fileName);	file.close();}
