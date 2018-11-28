#include "Line.h"

Line::Line(const double * arr)
{
    //Line, 2 sets of (X,Y)
    coord = new Vector2[2];

    coord[0].x = arr[0];
    coord[0].y = arr[1];

    coord[1].x = 20;
    coord[1].y = 30;

    std::cout << "coordinate is: " << coord[0].x << ", " << coord[0].y << std::endl;
    std::cout << "coordinate extra is: " << coord[1].x << ", " << coord[1].y << std::endl;
}

Line::~Line()
{
    delete [] coord;
}

//Inherited functions
std::string Line::getType() const
{
    return "Line";
}

double Line::area() const
{
    return -1;
}

double Line::circumference() const
{
    return 0;
}

double* Line::position() const
{
    double tmp[2];
    tmp[0] = (coord[0].x + coord[1].x)/2;
    tmp[1] = (coord[0].y + coord[1].y)/2;
    return tmp;
}

double Line::distance(Shape s) const
{
    double *tmp = this->position();
    double *other = s.position();

    //Distance-algorithm
    double dist = fabs( sqrt( pow(tmp[0] - other[0], 2) + pow(tmp[1] - other[1], 2) ) );
    return dist;
}

bool Line::isConvex() const
{
    return false;
}