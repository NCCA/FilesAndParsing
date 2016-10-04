#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


int main(int argc, char *argv[])
{
	if (argc <=1)
	{
		std::cout <<"Usage FileRead [filename] \n";
		exit(EXIT_FAILURE);
	}

	std::fstream fileIn;
	fileIn.open(argv[1],std::ios::in);
	if (!fileIn.is_open())
	{
		std::cout <<"File : "<<argv[1]<<" Not found Exiting \n";
		exit(EXIT_FAILURE);
	}

	std::string lineBuffer;
	unsigned long int lineNumber=1;
	while(!fileIn.eof())
	{
		getline(fileIn,lineBuffer,'\n');
		std::cout <<lineNumber<<" : "<<lineBuffer<<std::endl;
		++lineNumber;
	}
	fileIn.close();
	return EXIT_SUCCESS;
}












