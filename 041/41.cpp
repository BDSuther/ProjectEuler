#include <iostream>
#include <algorithm> //prev_permutation
#include "../PELib/PELib.h"

using namespace std;

/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?

Analysis shows that it MUST be either 7 or 4 digit pandigital because 3 divides all 5, 6, 8, or 9 pandigital numbers since the sum of their digits is divisible by 3

Will only consider 7-digit pandigital numbers.
*/

int main(){
	int digits[7] = {7, 6, 5, 4, 3, 2, 1};
	int num;

	do {
		num = digits[0];
		for(int i = 1; i < 7; i++){
			num *= 10;
			num += digits[i];
		}
		if(PELib::isPrime(num)){
			cout << num << endl;
			break;
		}
	} while (prev_permutation(digits,digits+7));
}