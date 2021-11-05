#ifndef LINE_H
#define LINE_H

#include <string>
#include "Shape.h"
using namespace std;

class Line : public Shape{
	public:
		Line();
    Line(double * x, double * y, string color);

		string toString();

		double area();

		~Line();

	private:
		bool test();
};

#endif