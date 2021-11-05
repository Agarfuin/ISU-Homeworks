#include <iostream>
#include <vector>
#include "Polynomial.h"

using namespace std;

int main() {
	Polynomial p1, p2;
	vector<int> v1, v2;
	Polynomial *p3;
	v1.push_back(2);
	v2.push_back(2);
	v2.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(0);
	v1.push_back(0);
	v1.push_back(0);

	p1.setCoefficients(&v1);
	p2.setCoefficients(&v2);

	p3 = p3->multiply(&p1, &p2);

	cout << "p1 = " << p1.toString() << endl;
	cout << "p2 = " << p2.toString() << endl;
	cout << "p3 = " << p3->toString() << endl; 

}


//v1 = 2+2x+3x^2+0x^3
//v2 = 2+x
//res = 4+4x+6x^2+0x^3....