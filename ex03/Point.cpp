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

Point::~Point()
{
    ;
}

Fixed sign (Point p1, Point p2, Point p3)
{
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp (Point v1, Point v2, Point v3, Point pt)
{
    Fixed d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(pt, v1, v2);
    d2 = sign(pt, v2, v3);
    d3 = sign(pt, v3, v1);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}
