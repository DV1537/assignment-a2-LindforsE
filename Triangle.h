#ifndef TRiANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape
{

private:

    struct Vector2
    {
        double x, y;
    };
    
    Vector2 * coord;

public:

    Triangle(const double * arr);
    ~Triangle();

    //Inherited functions
    virtual std::string getType() const;
    virtual double area() const;
    virtual double circumference() const;
    virtual double* position() const;
    virtual double distance(const Shape & s);
    virtual bool isConvex() const;

};


#endif //TRIANGLE_H