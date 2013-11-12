#include <iostream>
#include <fstream>
#include <cstdlib>

/*
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

question13.txt has the list on numbers

Soln: Only need to add at most the first 11 digits of the numbers since the rest cant affect more than the first 10 digits. considering the 11 digits will give
us a 13 digit number and anthing past the 11th digit cannot affect the first 10 digits of this new number.
*/
using namespace std;

int main (int argc, char* argv[]){

	char number[55], digit;
	int finalNum[13]={0};

	ifstream input("question13.txt");
	while (input.good()){
		input.getline(number, 55);
		for (int i=11;i >= 0; i--){
			digit = number[i];
			finalNum[i+1] += atoi(&digit);
		}
	}
	for (int i = 0 ; i < 49; i++){
		number[i]='a';
	}
	for (int i=11; i >0; i--){
		finalNum[i-1] += finalNum[i]/10;	
		finalNum[i] = finalNum[i]%10;
	}

	cout << "The first 10 digits are: ";

	for (int i=0; i<9 ; i++){
		cout << finalNum[i];
	}

	cout << endl;

}
