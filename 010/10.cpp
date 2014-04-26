#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include "../PELib/PELib.h"

/*The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/
//Using seive of Eratosthenes
using namespace std;

typedef unsigned long long int uint64_t;

uint64_t sumPrime (int below){
	
	uint64_t sum = 2;
	bool *a = (bool *)malloc(sizeof(bool)*(below + 1));
	fill_n(a, below + 1, true);

	PELib::eSieve(a, below);

	for (int i = 3; i < below ; i+=2){
		if (a[i]){
			 sum = sum +i;
		}
	}
	free(a);
	return sum;
}

int main (int argc, char*argv[]) {

	cout << "The sum of the primes below 2000000 is " << sumPrime (2000000) << endl;

}