#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {}


Point &Point::operator=(const Point &point)
{
    if (this != &point)
    {
        const_cast<Fixed&>(_x) = point.getX();
        const_cast<Fixed&>(_y) = point.getY();
    }
    return *this;
}

Point::Point(const Point &point) : _x(point.getX()), _y(point.getY()){}

Fixed Point::getX() const
{
    return this->_x;
}
Fixed Point::getY() const
{
	return this->_y;
}

Point::~Point(){}

Fixed area (Point p1, Point p2, Point p3)
{
	Fixed temp = ((p1.getX() * p2.getY() + p2.getX() * p3.getY() + p3.getX() * p1.getY()) - (p2.getX() * p1.getY() + p3.getX() * p2.getY() + p1.getX() * p3.getY())) / 2 ;

	return temp < 0 ? temp * -1 : temp;
}

bool bsp (Point v1, Point v2, Point v3, Point pt)
{
	Fixed p1, p2, p3, target;

	target = area(v1, v2, v3);
	p1 = area(pt, v2, v3);
	p2 = area(v1, pt, v3);
	p3 = area(v1, v2, pt);

	return (p1 != 0 && p2 != 0 && p3 != 0) && (target == p1 + p2 + p3);
}
