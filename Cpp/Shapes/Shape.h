#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

class Shape{
  protected:
    double * x;
    double * y;
    string color;
  
  public:
    Shape();
    Shape(double *x, double *y, string color);

    double * getX(){return x;}
    double * getY(){return y;}
    string getColor(){ return color;}
    void setX(double * x){this->x = x;}
    void setY(double * y){this->y = y;}
    void setColor(string color){this->color = color;}

    virtual double area() = 0;
    virtual string toString() = 0;
		
		~Shape();
};

#endif