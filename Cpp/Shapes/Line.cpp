#include <string>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "Line.h"
using namespace std;

Line::Line(){
  x = NULL;
  y = NULL;
  color = "No color set";
}

Line::Line(double * x, double * y, string color){
  this->x = x;
  this->y = y;
  this->color = color;
}

string Line::toString(){
	if(test()){
		string temp;
		temp += "This is a ";
		temp += color;
		temp += " line with coordinates";
		for(int i=0;i<2;i++){
			temp += "\n";
			temp += to_string(i+1);
			temp += ": ";
			temp += to_string(x[i]);
			temp += " ";
			temp += to_string(y[i]);
		}
		temp += "\n";
		return temp;
	}else
		return "Invalid object";
}

double Line::area(){
	double result;
	result = abs(sqrt(pow((x[1]-x[0]), 2) + pow((y[1]-y[0]), 2)));
	return result;
}

bool Line::test(){
	if(x == NULL || y == NULL)
		return false;
	return true;
}

Line::~Line(){}