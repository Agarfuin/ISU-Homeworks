#include <string>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "Triangle.h"
using namespace std;

Triangle::Triangle(){
  x = NULL;
  y = NULL;
  color = "No color set";
}

Triangle::Triangle(double * x, double * y, string color){
  this->x = x;
  this->y = y;
  this->color = color;
}

string Triangle::toString(){
	if(test()){
		string temp;
		temp += "This is a ";
		temp += color;
		temp += " triangle with coordinates";
		for(int i=0;i<3;i++){
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

double Triangle::area(){
	double result;
	result = 0.5 * abs((x[0]*y[1]+x[1]*y[2]+x[2]*y[0])-(x[1]*y[0]+x[2]*y[1]+x[0]*y[2]));
	return result;
}

bool Triangle::test(){
	if(x == NULL || y == NULL)
		return false;

	return true;
}

Triangle::~Triangle(){}