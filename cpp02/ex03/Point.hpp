#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y;

public:
	Point();
	Point( const float x, const float y );
	Point( const Point &point );
	~Point();

	Point&	operator=( const Point &point );

	Fixed	getX( void ) const ;
	Fixed	getY( void ) const ;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP
