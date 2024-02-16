#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	//std::cout << GREEN << "Point default constructor called" << RESET << std::endl;
}

Point::Point( const float x, const float y ) : _x(x), _y(y)
{
	//std::cout << GREEN << "Point constructor called" << RESET << std::endl;
}

Point::Point( const Point &point ) : _x(point._x), _y(point._y)
{
	//std::cout << PURPLE << "Point copy constructor called" << RESET << std::endl;
}

Point::~Point()
{
	//std::cout << RED << "Point destructor called" << RESET << std::endl;
}

Point&  Point::operator=( const Point &point )
{
	//std::cout << BLUE << "Point assignation operator called" << RESET << std::endl;
	if (this != &point)
	{
		(Fixed)this->_x = point.getX();
		(Fixed)this->_y = point.getY();
	}
	return (*this);
}
Fixed Point::getX( void ) const
{
	return (this->_x);
}

Fixed Point::getY( void ) const
{
	return (this->_y);
}
