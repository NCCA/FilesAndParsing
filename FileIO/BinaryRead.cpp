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

	std::array<Point,10> points;
	fileIn.read(reinterpret_cast <char *>(&points[0]),sizeof(Point)*points.size());

	for(auto p : points)
	{
		std::cout <<'['<<p.m_x<<','<<p.m_y<<','<<p.m_z<<"]\n";
	}

	fileIn.close();
	return EXIT_SUCCESS;
}









