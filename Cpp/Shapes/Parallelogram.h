#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include <string>
#include "Shape.h"
using namespace std;

class Parallelogram : public Shape{
	public:
		Parallelogram();
		Parallelogram(double *x, double *y, string color);

		string toString();
		
		double area();

		~Parallelogram();
		
	private:
    bool test();
};

#endif