#include <vector>
#include <string>

class Polynomial{
	public:
	Polynomial();
	Polynomial(std::vector<int> *c);

	std::vector<int> *getCoefficients(){
		return coefficients;
	}

	void setCoefficients(std::vector<int> *v){
		delete coefficients;
		coefficients = v;
	}

	Polynomial *add(Polynomial *p1, Polynomial *p2);
	Polynomial *subtract(Polynomial *p1, Polynomial *p2);
	Polynomial *multiply(Polynomial *p1, Polynomial *p2);

	std::string toString();

	~Polynomial();

	private:
	std::vector<int> *coefficients;
	
};