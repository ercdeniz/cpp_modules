#include "Point.hpp"

static Fixed absValue(Fixed value) {
	if (value < 0)
		return value * -1;
	return value;
}

static Fixed calculate(Point const pointA, Point const pointB, Point const pointC) {
	return (
		(pointA.getX() * (pointB.getY() - pointC.getY())) +
		(pointB.getX() * (pointC.getY() - pointA.getY())) +
		(pointC.getX() * (pointA.getY() - pointB.getY()))) / 2;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed ABC = absValue(calculate(a, b, c));
	Fixed PAB = absValue(calculate(point, a, b));
	Fixed PBC = absValue(calculate(point, b, c));
	Fixed PCA = absValue(calculate(point, c, a));

	return (ABC == PAB + PBC + PCA);
}
