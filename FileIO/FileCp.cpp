#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[])
{
	if (argc <=2)
	{
		std::cerr <<"Usage FileCP [infile] [outfile] \n";
		exit(EXIT_FAILURE);
	}

	std::ofstream fileOut;
	std::ifstream fileIn;

	fileIn.open(argv[1]);
	fileOut.open(argv[2]);

	// check to see if we can open the file
	if (!fileOut.is_open() && !fileIn.is_open())
	{
		std::cerr <<"Could not open one of the files : \n";
		exit(EXIT_FAILURE);
	}

	do
	{
		fileOut.put(fileIn.get());
	}	while(fileIn.good());
	fileOut.close();
	fileIn.close();

	return EXIT_SUCCESS;
}