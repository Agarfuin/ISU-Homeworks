#include <string>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "VerticalLine.h"
using namespace std;

VerticalLine::VerticalLine(){
	length = 0;
	x = NULL;
  y = NULL;
  color = "No color set";
}

VerticalLine::VerticalLine(double * x, double * y, double length, string color){
	this->x = x;
	this->y = y;
	this->color = color;
	this->length = length;
}

string VerticalLine::toString(){
	if(test()){
		string temp;
		temp += "This is a ";
		temp += color;
		temp += " vertical line with coordinates";
		temp += "\n";
		temp += to_string(1);
		temp += ": ";
		temp += to_string(x[0]);
		temp += " ";
		temp += to_string(y[0]);
		temp += "\n";
		temp += to_string(2);
		temp += ": ";
		temp += to_string(x[0]);
		temp += " ";
		temp += to_string(y[0]+length);
		temp += "\n";
		return temp;
	}else
		return "Invalid object";
}

double VerticalLine::area(){
	return length;
}

bool VerticalLine::test(){
	if(x == NULL || y == NULL)
		return false;
	return true;
}

VerticalLine::~VerticalLine(){}