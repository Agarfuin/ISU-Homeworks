#ifndef HORIZONTALLINE_H
#define HORIZONTALLINE_H

#include <string>
#include "Line.h"
using namespace std;

class HorizontalLine : public Line{
	public:
		HorizontalLine();
		HorizontalLine(double *x, double *y, double length, string color);

		string toString();

		double area();

		void setLength(double length){this->length = length;}

		~HorizontalLine();

	private:
		double length;
		bool test();
};

#endif