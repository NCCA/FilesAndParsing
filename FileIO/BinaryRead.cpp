#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>



class Point
{
	public :
		float m_x;
		float m_y;
		float m_z;
};

int main(int argc, char *argv[])
{

	if (argc <=1)
	{
		std::cout <<"Usage BinaryRead [filename] \n";
		exit(EXIT_FAILURE);
	}

	std::ifstream fileIn;
	fileIn.open(argv[1],std::ios::in | std::ios::binary);
	if (!fileIn.is_open())
	{
	std::cout <<"File : "<<argv[1]<<" Not found Exiting \n";
	exit(EXIT_FAILURE);
	}

	Point p[100];
	fileIn.read(reinterpret_cast <char *>(p),sizeof(Point)*100);

	for(int i=0; i<100; ++i)
	{
		std::cout <<"["<<p[i].m_x<<","<<p[i].m_y<<","<<p[i].m_z<<"]\n";
	}

	fileIn.close();
	return EXIT_SUCCESS;
}









