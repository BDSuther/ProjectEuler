#include <iostream>

using namespace std;
	
/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/

int digitSum(int exponent){

	unsigned int number[500] = {0};
	int remExp = exponent;	//how many exponents are remaining
	int finalIndex = 0;		//the furthest index in the number array that contains numbers
	int exp;				//the exponent we will go to
	int sum = 0;
	const int MAX_EXP = 28;	//since using UNSIGNED INT we can only go up to 9*2^28 before we cause overflow.
	number[0] = 1;
	
	while (remExp > 0){
		if (remExp > MAX_EXP){
			exp = MAX_EXP;
		} else {
			exp = remExp;
		}
		for(int i = exp; i > 0; i--){
			for(int j = 0; j <= finalIndex; j++){
				number[j] *= 2;
			}
		}

		remExp -= exp;

		//move over the number into the number buckets so that each contains only one digit
		for(int i = 0; i < 499; i++){
			number[i+1] += number[i]/10;
			number[i] = number[i] % 10;
			if (number[i+1] == 0){
				finalIndex = i; //all number[finalIndex+1] and further are 0
				break;
			}
		}
	}

	for (int i = 0; i <= finalIndex; i++){
		sum += number[i];
	}

	return sum;
}

int main (int argc, char* argv[]){


	cout << "The sum of the digits of 2^1000 is " << digitSum(1000) << endl;

}