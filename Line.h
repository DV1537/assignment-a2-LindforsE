#ifndef LINE_H
#define LINE_H
#include "Shape.h"

class Line : public Shape
{
private:

    struct Vector2
    {
        double x, y;
    };

    //int size;
    Vector2 * coord;

public:

    Line(const double * arr);
    ~Line();

    //Inherited functions
    virtual std::string getType() const;
    virtual double area() const;
    virtual double circumference() const;
    //virtual Vector2 position() const;
    virtual double* position() const;
    virtual double distance(const Shape & s);
    virtual bool isConvex() const;

};

#endif //LINE_H