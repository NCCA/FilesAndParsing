#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[])
{
	if (argc <=1)
	{
		std::cerr <<"Usage FileWrite [filename] "<<std::endl;
		exit(EXIT_FAILURE);
	}

	std::ifstream FileIn;

	FileIn.open(argv[1]);
	// check to see if we can open the file
	if (!FileIn.is_open())
	{
		std::cerr <<"Could not open File : "<<argv[1]<<" for writing \n";
		exit(EXIT_FAILURE);
	}
	char data;
	while ( !FileIn.eof() )
	{
		FileIn.get(data);
		std::cout <<data;
	}
	std::cout<<'\n';
	FileIn.close();
	return EXIT_SUCCESS;
}