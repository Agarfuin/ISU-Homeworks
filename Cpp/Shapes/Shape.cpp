#include "Shape.h"
#include <iostream>
using namespace std;

Shape::Shape(){
  x = new double[1];
  y = new double[1];
  color = "No color set";
}
    
Shape::Shape(double *x, double *y, string color){
    this->x = x;
    this->y = y;
    this->color = color;
}

Shape::~Shape(){}