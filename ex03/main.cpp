#include "Point.hpp"

using namespace std;

int main( void )
{
	cout << "spot inside = "<< bsp(Point(0,0), Point(0,5), Point(5,0), Point(1,1)) << endl;
	cout << "spot inside = "<< bsp(Point(0,0), Point(0,5), Point(5,0), Point(10,10)) << endl;
}