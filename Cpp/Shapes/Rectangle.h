#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include "Parallelogram.h"
using namespace std;

class Rectangle : public Parallelogram{
	public:
		Rectangle();
		Rectangle(double *x, double *y, string color);
		
		string toString();
		
		double area();

		~Rectangle();

	private:
    bool test();
};

#endif