#include <iostream>
#include <fstream>
#include <cstdlib>

/*
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

question13.txt has the list on numbers

maybe do a re-write using boost for a large digit number arithmetic
*/
using namespace std;

int main (int argc, char* argv[]){

	char number[55], digit;
	int finalNum[55]={0};

	ifstream input("question13.txt");
	while (input.good()){
		input.getline(number, 55);
		for (int i=49;i >= 0; i--){
			digit = number[i];
			finalNum[i+1] += atoi(&digit);
		}
	}
	for (int i=49; i >0; i--){
		finalNum[i-1] += finalNum[i]/10;	
		finalNum[i] = finalNum[i]%10;
	}

	cout << "The first 10 digits are: ";

	for (int i=0; i<9 ; i++){
		cout << finalNum[i];
	}

	cout << endl;

}
