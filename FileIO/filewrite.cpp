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

std::ofstream fileOut;

fileOut.open(argv[1]);
// check to see if we can open the file
if (!fileOut.is_open())
{
	std::cerr <<"Could not open File : "<<argv[1]<<" for writing "<<std::endl;
	exit(EXIT_FAILURE);
}

for (int i=0; i<10; ++i)
{
	fileOut << "Line number is "<<i<<endl;
}
fileOut.close();
return EXIT_SUCCESS;
}