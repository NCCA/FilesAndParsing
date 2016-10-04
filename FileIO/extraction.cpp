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

	std::ifstream fileIn;

	fileIn.open(argv[1]);
	// check to see if we can open the file
	if (!fileIn.is_open())
	{
		std::cerr <<"Could not open File : "<<argv[1]<<" for reading "<<"\n";
		exit(EXIT_FAILURE);
	}

	int a;
	char b;
	float c;
	double d;
	std::string s;

	fileIn>>a;
	fileIn>>b;
	fileIn>>c;
	fileIn>>d;
	fileIn>>s;

	fileIn.close();
	std::cout << a<<"\n"<<b<<"\n"<<c<<"\n"<<d<<"\n"<<s<<"\n";

	return EXIT_SUCCESS;
}