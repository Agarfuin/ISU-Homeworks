#include <iostream>

using namespace std;

int main()
{
	int choose1, pyramid_height, gap_pyramid, star_size, star_height, gap_star, fibonacci_index, fibonacci_sum, fibonacci_sum_prev, fibonacci_filler;
	cout << "Welcome to my first C++ program!" << endl;

	while(1){
		cout << "Please select a task to perform (-1 to exit):" << endl;
		cout << "1) Draw a pyramid" << endl;
		cout << "2) Draw a star" << endl;
		cout << "3) Compute the Fibonacci numbers" << endl;
		cin >> choose1;
		if(choose1 == 1) {
			while(1){
				cout << "Please enter the height of the pyramid (between 1 and 40):" << endl;
				cin >> pyramid_height;
				if(1 <= pyramid_height && pyramid_height <= 40){
					for(int i = 1; i<=pyramid_height; i++) {
						gap_pyramid = pyramid_height - i;
						for(int j = 0; j<gap_pyramid; j++)
							cout << " ";
						for(int j = 0; j<(2*i-1); j++)
							cout << "*";
						for(int j = 0; j<gap_pyramid; j++)
							cout << " ";
						cout << "\n";
					}
					break;
				}
				else
					cout << "You have entered an invalid value for height." << endl;
			}
		}
		else if(choose1 == 2) {
			while(1){
				cout << "Please enter the size of the star (between 1 and 20):" << endl;
				cin >> star_size;
				if(1 <= star_size && star_size <= 20){
					star_height = star_size * 2 + 1;
					for(int i = 1; i<=star_height/2; i++) {
						gap_star = i-1;
						for(int j = 0; j<gap_star; j++)
							cout << " ";
						cout << "*";
						for(int j = 0; j<(star_height-2*i); j++)
							cout << " ";
						cout << "*";
						for(int j = 0; j<gap_star; j++)
							cout << " ";
						cout << "\n";
					}
					for(int i = 0; i<star_height/2; i++)
						cout << " ";
					cout << "*";
					for(int i = 0; i<star_height/2; i++)
						cout << " ";
					cout << "\n";
					for(int i = 1; i<=star_height/2; i++) {
						gap_star = star_height/2 - i;
						for(int j = 0; j<gap_star; j++)
							cout << " ";
						cout << "*";
						for(int j = 0; j<(2*i-1); j++)
							cout << " ";
						cout << "*";
						for(int j = 0; j<gap_star; j++)
							cout << " ";
						cout << "\n";
					}
					break;
				}
				else
					cout << "You have entered an invalid value for size." << endl;
			}
		}
		else if(choose1 == 3) {
			while(1){
				cout << "Please enter the index of the Fibonacci number to be computed:" << endl;			//Can compute fibonacci numbers up to F(46)
				cin >> fibonacci_index;
				if(fibonacci_index >=0){
					if(fibonacci_index == 0)
						cout << "F(0) = 0" << endl;
					else{
						fibonacci_sum = 1;
						fibonacci_sum_prev = 0;
						for(int i = 1; i<fibonacci_index; i++) {
							fibonacci_filler = fibonacci_sum;
							fibonacci_sum = fibonacci_sum + fibonacci_sum_prev;
							fibonacci_sum_prev = fibonacci_filler;
						}
						cout << "F(" << fibonacci_index << ") = " << fibonacci_sum << endl;
					}
					break;
				}
				else
					cout << "You have entered an invalid value for index." << endl;
			}
		}
		else if(choose1 == -1) {
			break;
		}
		else
			cout << "You have entered an invalid value for selection." << endl;
	}

	
	return 0;
}