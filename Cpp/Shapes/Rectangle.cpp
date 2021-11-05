#include <string>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(){
	x = NULL;
  y = NULL;
  color = "No color set";
}

Rectangle::Rectangle(double *x, double *y, string color){
	this->x = x;
	this->y = y;
	this->color = color;
}

string Rectangle::toString(){
	if(test()){
		double x_remain[2], y_remain[2];
		x_remain[0] = x[0];
		y_remain[0] = y[1];
		y_remain[1] = y[0];
		x_remain[1] = x[1];
		string temp;
		temp += "This is a ";
		temp += color;
		temp += " rectangle with coordinates";
		for(int i=0;i<2;i++){
			temp += "\n";
			temp += to_string(i+1);
			temp += ": ";
			temp += to_string(x[i]);
			temp += " ";
			temp += to_string(y[i]);
		}
		for(int i=0;i<2;i++){
			temp += "\n";
			temp += to_string(i+3);
			temp += ": ";
			temp += to_string(x_remain[i]);
			temp += " ";
			temp += to_string(y_remain[i]);
		}
		temp += "\n";
		return temp;
	}else
		return "Invalid object";
}

double Rectangle::area(){
	double height, length, result;
	height = abs(y[1]-y[0]);
	length = abs(x[1]-x[0]);
	result = abs(height * length);
	return result;
}

bool Rectangle::test(){
	if(x == NULL || y == NULL)
		return false;
	return true;
}

Rectangle::~Rectangle(){}