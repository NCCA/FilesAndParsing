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
		std::cout <<"Usage BinaryWrite [filename] \n";
		exit(EXIT_FAILURE);
	}

	std::ofstream fileOut;
	fileOut.open(argv[1],std::ios::out | std::ios::binary);
	if (!fileOut.is_open())
	{
		std::cout <<"File : "<<argv[1]<<" Not found Exiting \n";
		exit(EXIT_FAILURE);
	}

	Point p[10];

	for(int i=0; i<10; ++i)
	{
		p[i].m_x=i; p[i].m_y=i; p[i].m_z=i;
	}

	fileOut.write(reinterpret_cast <char *>(p),sizeof(Point)*10);

	fileOut.close();
	return EXIT_SUCCESS;
}

















