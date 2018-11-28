#include "Triangle.h"

Triangle::Triangle(const double * arr)
{
    coord = new Vector2[3];

    coord[0].x = arr[0];
    coord[0].y = arr[1];
    
    coord[1].x = arr[2];
    coord[1].y = arr[3];

    coord[2].x = arr[4];
    coord[2].y = arr[5];
}

Triangle::~Triangle()
{
    delete [] coord;
}

//Inherited functions
std::string Triangle::getType() const
{
    return "Triangle";
}

double Triangle::area() const
{
    // | ( Ax(By - Cy) + Bx(Cy - Ay) + Cx (Ay - By)  ) / 2 |
    double area = ( (coord[0].x * (coord[1].y - coord[2].y) ) + ( coord[1].x * (coord[2].y - coord[0].y) ) + ( coord[2].x * (coord[0].y - coord[1].y) ) );
    area *= 0.5;
    area = std::fabs(area);
    return area;
}

double Triangle::circumference() const
{
    //AB + BC + CA

    //AB coord[0] -> coord[1]
    double distAB = fabs( sqrt( pow(coord[0].x - coord[1].x,2) + pow(coord[0].y - coord[1].y ,2) ) );
    //BC coord[1] -> coord[2]
    double distBC = fabs( sqrt( pow(coord[1].x - coord[2].x,2) + pow(coord[1].y - coord[2].y ,2) ) );
    //CA coord[2] -> coord[0]
    double distCA = fabs( sqrt( pow(coord[2].x - coord[0].x,2) + pow(coord[2].y - coord[0].y ,2) ) );

    return distAB + distBC + distCA;
}

double* Triangle::position() const
{
    double tmp[2];
    
    //( (Ax + Bx + Cx)/3 , (Ay + By + Cy)/3 )
    tmp[0] = (coord[0].x + coord[1].x + coord[2].x)/3;
    tmp[1] = (coord[0].y + coord[1].y + coord[2].y)/3;

    return tmp;
}

double Triangle::distance(Shape s) const
{
    double *tmp = this->position();
    double *other = s.position();

    //Distance-algorithm
    double dist = fabs( sqrt( pow(tmp[0] - other[0], 2) + pow(tmp[1] - other[1], 2) ) );
    return dist;
}

bool Triangle::isConvex() const
{
    return true;
}