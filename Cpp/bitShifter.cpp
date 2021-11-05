#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
 
string HexToBin(string hexdec) {
	long int i = 0;
	string temp;

	while (hexdec[i]) {

		switch (hexdec[i]) {
		case '0':
			temp += "0000";
			break;
		case '1':
			temp += "0001";
			break;
		case '2':
			temp += "0010";
			break;
		case '3':
			temp += "0011";
			break;
		case '4':
			temp += "0100";
			break;
		case '5':
			temp += "0101";
			break;
		case '6':
			temp += "0110";
			break;
		case '7':
			temp += "0111";
			break;
		case '8':
			temp += "1000";
			break;
		case '9':
			temp += "1001";
			break;
		case 'A':
		case 'a':
			temp += "1010";
			break;
		case 'B':
		case 'b':
			temp += "1011";
			break;
		case 'C':
		case 'c':
			temp += "1100";
			break;
		case 'D':
		case 'd':
			temp += "1101";
			break;
		case 'E':
		case 'e':
			temp += "1110";
			break;
		case 'F':
		case 'f':
			temp += "1111";
			break;
		default:
			cout << "\nInvalid hexadecimal digit " << hexdec[i];
		}
		i++;
	}
	return temp;
}

string decToHexa(int n) {
	string hex_num;
	while(n != 0){
		if(n%16<10)
			hex_num += to_string(n%16);
		else
			if(n%16 == 10)
				hex_num += "a";
			else if(n%16 == 11)
				hex_num += "b";
			else if(n%16 == 12)
				hex_num += "c";
			else if(n%16 == 13)
				hex_num += "d";
			else if(n%16 == 14)
				hex_num += "e";
			else if(n%16 == 15)
				hex_num += "f";

		n = n/16;
	}

	return hex_num;
}

void reverseStr(string& str) {
	int n = str.length();
 
	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
}
 
int main() {
	int sayi1 = 0xd4a9;
	string bin_sayi;
	string hex_sayi = decToHexa(sayi1);
	reverseStr(hex_sayi);
	bin_sayi = HexToBin(hex_sayi);
	reverseStr(bin_sayi);
	for(int i=0;i<2;i++)
		bin_sayi += "0";
	reverseStr(bin_sayi);

	if(bin_sayi[3] == '1')
		bin_sayi[3] = '0';
	else
		bin_sayi[3] = '1';

	char bit1 = bin_sayi[3];
	
	if(bin_sayi[10] == '1')
		bin_sayi[10] = '0';
	else
		bin_sayi[10] = '1';

	char bit2 = bin_sayi[10];

	cout << "Sayı: " << bin_sayi << "\n" << "4. bit: " << bit1 << "\n" << "11. bit: " << bit2 << endl;

	return 0;
}