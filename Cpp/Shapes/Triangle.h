#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include "Shape.h"
using namespace std;

class Triangle : public Shape{
  public:
    Triangle();
    Triangle(double * x, double * y, string color); 
		
    string toString();
		
    double area();

		~Triangle();

    private:
      bool test();
};

#endif