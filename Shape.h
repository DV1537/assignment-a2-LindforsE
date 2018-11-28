#ifndef SHAPE_H
#define SHAPE_H

#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

class Shape
{

public:
    
    virtual std::string getType() const;
    virtual double area() const;
    virtual double circumference() const;
    virtual double* position() const;
    virtual double distance(Shape s) const;

    virtual bool isConvex() const;

};

#endif //SHAPE_H