#ifndef POINT_H
#define POINT_H
#include "Shape.h"

class Point : public Shape
{

private:

    struct Vector2
    {
        double x, y;
    };

    Vector2 * coord;

public:

    Point(const double * arr);
    ~Point();
    
    //Inherited functions
    virtual std::string getType() const;
    virtual double area() const;
    virtual double circumference() const;
    virtual double* position() const;
    virtual double distance(Shape s) const;
    virtual bool isConvex() const;

};


#endif //POINT_H