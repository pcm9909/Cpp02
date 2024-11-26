#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const Fixed x, const Fixed y);
		Point &operator=(const Point &point);
		Point(const Point &point);
		~Point();
		Fixed getX() const;
		Fixed getY() const;
	private:
		Fixed const _x;
		Fixed const _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif