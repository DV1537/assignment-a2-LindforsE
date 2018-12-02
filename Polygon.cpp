#include "Polygon.h"

Polygon::Polygon(double arr[], int n)
{
    //Todo
    //decide int size, AKA nrOfElements;
    //Can't find size of array in function, array is passed by reference.
    
    this->size = n;
    
    //remember size/2, due to element-pair = coordinate (X, Y)
    coord = new Vector2[size/2];

    int j = 0;
    //for-loop to fill coord with every element from arr[]
    for(int i = 0; i < size/2; i++)
    {
        coord[i].x = arr[j];
        j++;
        coord[i].y = arr[j];
        j++;
    }
}

Polygon::~Polygon()
{
    delete [] coord;
}

//Inherited functions
std::string Polygon::getType() const
{
    return "Polygon";
}

double Polygon::area() const
{
    double areaValue = 0;
    
    if(this->isConvex() == true)
    {
        //area = 1/2 * abs ( (X1 * Y2 - X2 * Y1) + (X2 * Y3 - X3 * Y2) + ... + (Xn * Y1 - X1 * Yn) )
        //Size = nrOfElements. Coordinates are in pairs -> half of size
        int maxValue = size/2;
        for(int i = 0; i < maxValue -1; i++)
        {
            //(Xi * X(i+1) - X(i+1) * Yi)
            areaValue += (coord[i].x * coord[i+1].y) - (coord[i+1].x * coord[i].y);
        }
        //Last and first coordinate
        areaValue += (coord[maxValue-1].x * coord[0].y) - (coord[0].x * coord[maxValue-1].y);

        //abs and divide by .5
        areaValue = abs(areaValue);
        areaValue *= 0.5;
    }
    else
    {
        areaValue = -1;
    }

    return areaValue;
}

double Polygon::circumference() const
{
    //add up all side lengths

    double distance = 0;
    int maxValue = size/2;

    //Length between two points
    // abs( sqrt( pow(coord[0].x - coord[1].x,2) + pow(coord[0].y - coord[1].y ,2) ) );    

    //loop through all points
    for(int i = 0; i < maxValue -1; i++)
        distance += fabs( sqrt( pow(coord[i].x - coord[i+1].x,2) + pow(coord[i].y - coord[i+1].y ,2) ) );

    //last point and first point
    distance += fabs( sqrt( pow(coord[maxValue-1].x - coord[0].x,2) + pow(coord[maxValue-1].y - coord[0].y ,2) ) );

    return distance;
}

double* Polygon::position() const
{
    int maxValue = size/2;
    double center[2];
    double tmpX = 0, tmpY = 0, tmpA = 0, A = 0;
    
    //center.x (center[0]) += (X0 + X1) * ( (X0 * Y1) - (X1 * Y0) )
    //center.y (center[1]) += (Y0 + Y1) * ( (X0 * Y1) - (X1 * Y0) )

    //loop through all but last point
    for(int i = 0; i < maxValue -1; i++)
    {
        tmpA = (coord[i].x * coord[i+1].y) - (coord[i+1].x * coord[i].y);
        A += tmpA;
        tmpX += (coord[i].x + coord[i+1].x) * tmpA;
        tmpY += (coord[i].y + coord[i+1].y) * tmpA;
    }

    //last point and first point
    tmpA = (coord[maxValue-1].x * coord[0].y) - (coord[0].x * coord[maxValue-1].y);
    A += tmpA;
    tmpX += (coord[maxValue-1].x + coord[0].x) * tmpA;
    tmpY += (coord[maxValue-1].y + coord[0].y) * tmpA;

    //half
    A *= 0.5;

    //multiply by 6
    tmpX /= (6.0 * A);
    tmpY /= (6.0 * A);

    //insert center coordinates to return array
    center[0] = tmpX;
    center[1] = tmpY;

    return center;
}

double Polygon::distance(const Shape & s)
{
    double *tmp = this->position();
    double *other = s.position();

    //Distance-algorithm
    double dist = fabs( sqrt( pow(tmp[0] - other[0], 2) + pow(tmp[1] - other[1], 2) ) );
    return dist;
}

bool Polygon::isConvex() const
{
    //Todo
    //False if one or more interior angle(s) are greater than 180 degrees.
    //True if all interior angles are less than 180 degrees.

    //Works only for polygons with 3 or more vertices

    //Coordinates for point A and B
    double ax = 0, ay = 0, bx = 0, by = 0;
    double xSign = 0, ySign = 0, xFlips = 0, yFlips = 0;
    double xFirstSign = 0, yFirstSign = 0;
    double w = 0, wSign = 0;
    int curr = size/2 -2;
    int next = size/2 -1;
    int prev;

    for(int i = 0; i < (size/2)-1; i++)
    {
        prev = curr;
        curr = next;
        next = i;
        //Coordinates to use
        ax = coord[next].x - coord[curr].x;
        ay = coord[next].y - coord[curr].y;

        bx = coord[curr].x - coord[prev].x;
        by = coord[curr].y - coord[prev].y;

        //Keep track if all edges has positive/negative angles
        if(ax > 0)
        {
            if(xSign == 0)
                xFirstSign = 1;
            else if(xSign < 0)
                xFlips++;

            xSign = 1;
        }
        else if(ax < 0)
        {
            if(xSign == 0)
                xFirstSign = -1;
            else if(xSign > 0)
                xFlips++;
            
            xSign = -1;
        }
        //If there's a sign-change (+ -) of the angle
        if(xFlips > 2)
            return false;
        
        //Keep track if all edges has positive/negative angles
        if(ay > 0)
        {
            if(ySign == 0)
                yFirstSign = 1;
            else if(ySign < 0)
                yFlips++;
            
            ySign = 1;
        }
        else if(ay < 0)
        {
            if(ySign == 0)
                yFirstSign = -1;
            else if(ySign > 0)
                yFlips++;
            
            ySign = -1;
        }
        //If there's a sign-change (+ -) of the angle
        if(yFlips > 2)
            return false;

        //Orientation of current pair
        w = bx * ay - ax * by;

        //Check if it differ from previous pairs, concave if it does
        if( (wSign == 0) && (w != 0) )
            wSign = w;
        else if( (wSign > 0) &&(w < 0) )
            return false;
        else if( (wSign < 0) && (w > 0) )
            return false;
    }

    //Final sign flips (wraparound)
    if( (xSign != 0) && (xFirstSign != 0) && (xSign != xFirstSign) )
        xFlips++;
    
    if( (yFlips != 0) && (yFirstSign != 0) && (ySign != yFirstSign) )
        yFlips++;
    
    //Concave if sign-flip after the "wraparound"
    if( (xFlips != 2) || yFlips != 2 )
        return false;

    //Convex polygon
    return true;
}