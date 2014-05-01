#include <iostream>
#include <algorithm>
#include "../PELib/PELib.h"

/*The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?
*/

//similar check to the pandigital method in PELib
bool sameDigits(int a, int b){
	int digits[10] = {0};

	while(a > 0){
		digits[a % 10]++;
		digits[b % 10]--;
		a /= 10;
		b /= 10;
	}
	for(int i = 0; i < 10; i++){
		if(digits[i] != 0){
			return false;
		}
	}
	return true;
}

void findSequence(int *primes, bool *a){

	for(int i = 1000; i <= 9997; i++){
		if(a[i]){		
			for(int j = 1; i + j * 2 < 10000; j++){
				if(a[i+j] && a[i + j * 2]){
					if(sameDigits(i, i + j) && sameDigits(i, i + 2 * j) && i != 1487){
						primes[0]= i;
						primes[1] = i + j;
						primes[2] = i + 2 * j;
					}
				}
			}
		}
		if(primes[0] != 0){ break; }
	}
}

int main(){
	int primes[3] = {0};
	bool a[10000];
	std::fill_n(a, 10000, true);

	PELib::eSieve(a, 9999);

	findSequence(primes, a);

	std::cout << "The 12-digit number is " << primes[0] << primes[1] << primes[2] << "." << std::endl;
}