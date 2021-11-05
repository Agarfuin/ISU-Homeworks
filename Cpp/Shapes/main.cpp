#include <iostream>
#include <vector>
#include <string>
#include "time.h"
#include "Shape.h"
#include "Line.h"
#include "Triangle.h"
#include "Parallelogram.h"
#include "Rectangle.h"
#include "HorizontalLine.h"
#include "VerticalLine.h"

using namespace std;

int main() {
	int counter=0;
	double sum=0;
	vector <Shape*> shapes;
	srand((unsigned) time(NULL));
	string shape_types[6] = {"Line", "Triangle", "Parallelogram", "VerticalLine", "HorizontalLine", "Rectangle"};
	string colors[5] = {"Red", "Blue", "Green", "Yellow", "Purple"};

	for(int i=0;i<10000;i++){
		int rand_int;
		string rand_color;

		rand_color = colors[rand()%5];
		rand_int = rand()%6;

		if(shape_types[rand_int] == "Line"){
			double rand_array_x[2] = {(double) rand()/RAND_MAX, (double) rand()/RAND_MAX};
			double rand_array_y[2] = {(double) rand()/RAND_MAX, (double) rand()/RAND_MAX};
			Line rand_line;
			rand_line.setColor(rand_color);
			rand_line.setX(rand_array_x);
			rand_line.setY(rand_array_y);
			Line * temp = &rand_line;
			shapes.push_back(temp);
		}

		else if(shape_types[rand_int] == "Triangle"){
			double rand_array_x[3] = {(double) rand()/RAND_MAX, (double) rand()/RAND_MAX, (double) rand()/RAND_MAX};
			double rand_array_y[3] = {(double) rand()/RAND_MAX, (double) rand()/RAND_MAX, (double) rand()/RAND_MAX};
			Triangle rand_tri;
			rand_tri.setColor(rand_color);
			rand_tri.setX(rand_array_x);
			rand_tri.setY(rand_array_y);
			Triangle * temp = &rand_tri;
			shapes.push_back(temp);
			counter += 1;
			sum += rand_tri.area();
		}

		else if(shape_types[rand_int] == "Parallelogram"){
			double rand_array_x[3] = {(double) rand()/RAND_MAX, (double) rand()/RAND_MAX, (double) rand()/RAND_MAX};
			double rand_array_y[3] = {(double) rand()/RAND_MAX, (double) rand()/RAND_MAX, (double) rand()/RAND_MAX};
			Parallelogram rand_para;
			rand_para.setColor(rand_color);
			rand_para.setX(rand_array_x);
			rand_para.setY(rand_array_y);
			Parallelogram * temp = &rand_para;
			shapes.push_back(temp);
		}

		else if(shape_types[rand_int] == "VerticalLine"){
			double rand_array_x[1] = {(double) rand()/RAND_MAX};
			double rand_array_y[1] = {(double) rand()/RAND_MAX};
			double rand_length = rand()%1000;
			VerticalLine rand_vert_line;
			rand_vert_line.setColor(rand_color);
			rand_vert_line.setX(rand_array_x);
			rand_vert_line.setY(rand_array_y);
			rand_vert_line.setLength(rand_length);
			VerticalLine * temp = &rand_vert_line;
			shapes.push_back(temp);
		}

		else if(shape_types[rand_int] == "HorizontalLine"){
			double rand_array_x[1] = {(double) rand()/RAND_MAX};
			double rand_array_y[1] = {(double) rand()/RAND_MAX};
			double rand_length = rand()%1000;
			HorizontalLine rand_hori_line;
			rand_hori_line.setColor(rand_color);
			rand_hori_line.setX(rand_array_x);
			rand_hori_line.setY(rand_array_y);
			rand_hori_line.setLength(rand_length);
			HorizontalLine * temp = &rand_hori_line;
			shapes.push_back(temp);
		}

		else if(shape_types[rand_int] == "Rectangle"){
			double rand_array_x[2] = {(double) rand()/RAND_MAX, (double) rand()/RAND_MAX};
			double rand_array_y[2] = {(double) rand()/RAND_MAX, (double) rand()/RAND_MAX};
			Rectangle rand_rect;
			rand_rect.setColor(rand_color);
			rand_rect.setX(rand_array_x);
			rand_rect.setY(rand_array_y);
			Rectangle * temp = &rand_rect;
			shapes.push_back(temp);
		}

		else
			cout << "Failed while creating object." << endl;
	}

	cout << "Total number of Triangle objects created: " << counter << endl;
	cout << "Area Sum: " << sum << endl;
	cout << "Average: " << sum/counter << endl;
	
}