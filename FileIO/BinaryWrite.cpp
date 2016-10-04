#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <array>


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

	std::array<Point ,10>points;
	int i=0;
	for(auto &p : points)
	{
		p.m_x=i; 
		p.m_y=i; 
		p.m_z=i;
		++i;
	}

	fileOut.write(reinterpret_cast<char *>(&points[0].m_x) ,sizeof(Point)*points.size());
	fileOut.close();
	return EXIT_SUCCESS;
}

















