#include <iostream>
#include "math.h"
#include <stdint.h>

//Using seive of Eratosthenes
using namespace std;

uint64_t sumPrime (int below){
	bool *a=(bool*)malloc (below * sizeof(bool));
	for (int i = 2 ; i < below ; i ++){
		a[i] = 1;
	}

	uint64_t sum = 2;

	for (int j = 3; j < floor(sqrt(below));j+=2) {
		if (a[j]){
			for (int i=j*2 ; i < below ; i+=j){
				a[i]=0;
			}
		}
	}
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