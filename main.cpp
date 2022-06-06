
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include "TankList.h"
#include "engine.h"
#include "input.h"
#include "output.h"

using namespace std;


int main(int argc, char* argv[]) /// files taking from command line
{
	if (argc > 1)
	{
		string inputFilename = argv[1];
		string outputFilename = argv[2];
		Input inputs;
		Output outputs;
		inputs.readInputs(inputFilename);
		outputs.writeDatas(outputFilename);
	}
	
}




