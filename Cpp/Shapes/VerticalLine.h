#ifndef VERTICALLINE_H
#define VERTICALLINE_H

#include <string>
#include "Line.h"
using namespace std;

class VerticalLine : public Line{
	public:
		VerticalLine();
		VerticalLine(double *x, double *y, double length, string color);

		string toString();

		double area();

		void setLength(double length){this->length = length;}

		~VerticalLine();

	private:
		double length;
		bool test();
};

#endif