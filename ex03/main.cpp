#include "Point.hpp"

int main( void )
{
	std::cout << "spot inside = "<< bsp(Point(0,0), Point(0,5), Point(5,0), Point(1,1)) << std::endl;
	std::cout << "spot outside = "<< bsp(Point(0,0), Point(0,5), Point(5,0), Point(5,5)) << std::endl;
	std::cout << "spot edge = "<< bsp(Point(0,0), Point(0,5), Point(5,0), Point(0,0)) << std::endl;
}