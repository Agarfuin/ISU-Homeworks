#include "Polynomial.h"
#include <string>

using namespace std;

Polynomial::Polynomial(){
	coefficients = new vector<int>(1);
	coefficients->push_back(0);
}

Polynomial::Polynomial(vector<int> *coefficients){
	this->coefficients = coefficients;
}

Polynomial *Polynomial::add(Polynomial *p1, Polynomial *p2){
	vector<int> *result = new vector<int>();
	int p1_size = p1->coefficients->size();
	int p2_size = p2->coefficients->size();
	if(p1_size > p2_size){
		for(int i = 0;i<p2_size;i++){
			result->push_back((p1->coefficients->at(i))+(p2->coefficients->at(i)));
		}
		for(int i = p2_size;i<p1_size;i++){
			result->push_back(p1->coefficients->at(i));
		}
	}
	else{
		for(int i = 0;i<p1_size;i++){
			result->push_back((p1->coefficients->at(i))+(p2->coefficients->at(i)));
		}
		for(int i = p1_size;i<p2_size;i++){
			result->push_back(p2->coefficients->at(i));
		}
	}
	
	return new Polynomial(result);
}

Polynomial *Polynomial::subtract(Polynomial *p1, Polynomial *p2){
	vector<int> *result = new vector<int>();
	int p1_size = p1->coefficients->size();
	int p2_size = p2->coefficients->size();
	if(p1_size > p2_size){
		for(int i = 0;i<p2_size;i++){
			result->push_back((p1->coefficients->at(i))-(p2->coefficients->at(i)));
		}
		for(int i = p2_size;i<p1_size;i++){
			result->push_back(p1->coefficients->at(i));
		}
	}
	else{
		for(int i = 0;i<p1_size;i++){
			result->push_back((p1->coefficients->at(i))-(p2->coefficients->at(i)));
		}
		for(int i = p1_size;i<p2_size;i++){
			result->push_back(-(p2->coefficients->at(i)));
		}
	}
	
	return new Polynomial(result);
}

Polynomial *Polynomial::multiply(Polynomial *p1, Polynomial *p2){
	int p1_size = p1->coefficients->size();
	int p2_size = p2->coefficients->size();
	vector<int> *result = new vector<int>(p1_size+p2_size);
	for(int i = 0; i<p1_size+p2_size; i++){
		result->at(i) = 0;
	}
	for(int i = 0; i<p1_size; i++){
		for(int j = 0; j<p2_size; j++){
			result->at(i+j)+=p1->getCoefficients()->at(i) * p2->getCoefficients()->at(j);
		}
	}

	return new Polynomial(result);
}

string Polynomial::toString(){
	string result;
	for(int i = 0; i<coefficients->size(); i++){
		if(coefficients->at(i)!=0){
			if(i==0){
				result += to_string(coefficients->at(i));
				result += "+";
			}
			else{
				if(coefficients->at(i)!=1){
					result += to_string(coefficients->at(i));
				}
				result += "x^";
				result += to_string(i);
				if(i!=(coefficients->size()-1))
					result += "+";
			}
		}
	}

	if(result[result.length()-1] == '+')
		result[result.length()-1] = '\0';

	return result;
}

Polynomial::~Polynomial(){
}