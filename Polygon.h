#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.h"

class Polygon : public Shape
{

private:

    struct Vector2
    {
        double x,y;
    };
    Vector2 * coord;
    int size;

public:

    Polygon(double arr[], int);
    ~Polygon();

    //Inherited functions
    virtual std::string getType() const;
    virtual double area() const;
    virtual double circumference() const;
    virtual double* position() const;
    virtual double distance(const Shape & s);
    virtual bool isConvex() const;

};

#endif //POLYGON_H