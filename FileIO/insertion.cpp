#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main(int argc, char *argv[])
{
	if (argc <=1)
	{
		std::cerr <<"Usage FileWrite [filename] "<<std::endl;
		exit(EXIT_FAILURE);
	}

	std::ofstream fileOut;

	fileOut.open(argv[1],std::ios::out);

	// check to see if we can open the file
	if (!fileOut.is_open())
	{
		std::cerr <<"Could not open File : "<<argv[1]<<" for writing \n";
		exit(EXIT_FAILURE);
	}

	int a=10;
	char b='c';
	float c=22.3;
	double d=0.23232323299;
	std::string s("hello file transfer");

	fileOut<<a<<std::endl;
	fileOut<<b<<std::endl;
	fileOut<<c<<std::endl;
	fileOut<<(double)d<<std::endl;
	fileOut<<s<<std::endl;

	fileOut.close();
	return EXIT_SUCCESS;
}













