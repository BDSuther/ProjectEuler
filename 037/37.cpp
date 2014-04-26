#include <iostream>
#include <cstdlib>
#include "../PELib/PELib.h"

using namespace std;

/*
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/
bool isTrunc(int prime, bool *a){
	int p = prime;
	int digits = 1;
	//right
	while(p > 10){
		p /= 10;
		digits *= 10;
		if(!a[p]){
			return false;
		}
	}
	p = prime;
	//left
	while(p > 10){
		p = p % digits;
		digits /= 10;
		if(!a[p]){
			return false;
		}
	}
	return true;
}

int main(){
	const int UPPERBOUND = 1000000;
	int sum = 0, num = 0;

	bool a[UPPERBOUND + 1];
	fill_n(a, UPPERBOUND + 1, true);

	PELib::eSieve(a, UPPERBOUND);

	for(int i = 23; i < UPPERBOUND; i++){
		if(a[i]){
			if(isTrunc(i, a)){
				sum += i;
				num ++;
				//since no clear upper bound
				if(num == 11){
					//cout << "Found all 11" << endl;
					break;
				}
			}
		}
	}
	cout << "The sum of left and right truncateable primes is " << sum << endl;
}