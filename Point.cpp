#include "Point.h"
#include "Shape.h"

Point::Point(const double * arr)
{
    //Point, 1 set of (X,Y)
    coord = new Vector2[1];

    coord[0].x = arr[0];
    coord[0].y = arr[1];
}

Point::~Point()
{
    delete [] coord;
}

//Inherited functions
std::string Point::getType() const
{
    return "Point";
}

double Point::area() const
{
    return -1;
}

double Point::circumference() const
{
    return 0;
}

double* Point::position() const
{
    double tmp[2];
    tmp[0] = coord[0].x;
    tmp[1] = coord[0].y;
    return tmp;
}

double Point::distance(const Shape & s)
{
    //center-coordinates of other shape
    double *tmp = s.position();

    //Distance-algorithm
    double dist = abs( sqrt( pow(coord[0].x - tmp[0], 2) + pow(coord[0].y - tmp[1], 2) ) );
    return dist;
}

bool Point::isConvex() const
{
    return false;
}