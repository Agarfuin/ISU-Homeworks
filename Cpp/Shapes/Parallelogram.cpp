#include <string>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "Parallelogram.h"
using namespace std;

Parallelogram::Parallelogram(){
	x = NULL;
  y = NULL;
  color = "No color set";
}

Parallelogram::Parallelogram(double *x, double *y, string color){
	this->x = x;
	this->y = y;
	this->color = color;
}

string Parallelogram::toString(){
	if(test()){
		double x_3, y_3;

		x_3 = x[0] + x[2] - x[1];
		y_3 = y[0] + y[2] - y[1];
		string temp;
		temp += "This is a ";
		temp += color;
		temp += " parallelogram with coordinates";
		for(int i=0;i<3;i++){
			temp += "\n";
			temp += to_string(i+1);
			temp += ": ";
			temp += to_string(x[i]);
			temp += " ";
			temp += to_string(y[i]);
		}
		temp += "\n";
		temp += "4: ";
		temp += to_string(x_3);
		temp += " ";
		temp += to_string(y_3);
		temp += "\n";
		return temp;
	}else
		return "Invalid object";
}

double Parallelogram::area(){
	double x_3, y_3, result;
	x_3 = x[0];
	y_3 = y[0];
	result = abs(((x[0]*y[1])+(x[1]*y[2])+(x[2]*y_3)) - ((x_3*y[2])+(x[2]*y[1])+(x[1]*y[0])));
	return result;
}

bool Parallelogram::test(){
	if(x == NULL || y == NULL || (x[0]==x[1]&&x[1]==x[2]) || (y[0]==y[1]&&y[1]==y[2]))
		return false;
	return true;
}

Parallelogram::~Parallelogram(){}