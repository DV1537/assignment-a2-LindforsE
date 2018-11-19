#include "Shape.h"
#include "Point.h"

int main(int argc, const char * argv[])
{
    int size = 2;
    double a = 0;
    int n = 0;

    //std::cout.setprecision() only available with iomanip
    //std::cout.precision() doesn't work for decimals

    //(new, mem-leak)
    double * numbers = new double[size];
   
    //Read numbers from file. filename through argv[]
    std::ifstream myReadFile;
    myReadFile.open(argv[1]);

    //If file can't be opened, throw
    if (!(myReadFile.is_open()))
    {
        throw ("error opening file");
    }
    else
    {
        //Read loop
        while (!(myReadFile.eof()))
        {
            //if a number
            if (myReadFile >> a)
            {   
                numbers[n] = a;
                n++;
                //if no space in array, expand
                if (n >= size)
                {
                    size = size * 2;
                    //1. New bigger array (new, mem-leak)
                    double * tmp = new double[size];
                    //2. Copy elements to new array
                    for (int i = 0; i < n; i++)
                        tmp[i] = numbers[i];

                    //3. Delete pointer (del, mem-leak)
                    delete [] numbers;
                    //4. Redirect pointer
                    numbers = tmp;
                }
            }   
            //if not a number
            else
            {
                myReadFile.clear();
                myReadFile.ignore(10, ' ');
            }
        }
    }
    myReadFile.close();
    
    //Only run if input-elements are even

    //1 point(s) = Point
    //2 point(s) = Line
    //3 point(s) = Triangle
    //4 or more point(s) = Polygon

    //Delete dynamic array (del, mem leak)
    delete [] numbers;

    return 0;
}