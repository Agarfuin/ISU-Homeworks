#include <string>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "HorizontalLine.h"
using namespace std;

HorizontalLine::HorizontalLine(){
	length = 0;
	x = NULL;
  y = NULL;
  color = "No color set";
}

HorizontalLine::HorizontalLine(double * x, double * y, double length, string color){
	this->x = x;
	this->y = y;
	this->color = color;
	this->length = length;
}

string HorizontalLine::toString(){
	if(test()){
		string temp;
		temp += "This is a ";
		temp += color;
		temp += " horizontal line with coordinates";
		temp += "\n";
		temp += to_string(1);
		temp += ": ";
		temp += to_string(x[0]);
		temp += " ";
		temp += to_string(y[0]);
		temp += "\n";
		temp += to_string(2);
		temp += ": ";
		temp += to_string(x[0]+length);
		temp += " ";
		temp += to_string(y[0]);
		temp += "\n";
		return temp;
	}else
		return "Invalid object";
}

double HorizontalLine::area(){
	return length;
}

bool HorizontalLine::test(){
	if(x == NULL || y == NULL)
		return false;
	return true;
}

HorizontalLine::~HorizontalLine(){}