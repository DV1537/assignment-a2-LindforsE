#ifndef SHAPE_H
#define SHAPE_H

#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

class Shape
{

public:
    
    virtual std::string getType() const = 0;
    virtual double area() const = 0;
    virtual double circumference() const = 0;
    //virtual Vector2 position() const;
    virtual double* position() const = 0;
    virtual double distance(const Shape & s) = 0;

    virtual bool isConvex() const = 0;

};

#endif //SHAPE_H