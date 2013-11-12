#include <iostream>
#include <cstdlib>

using namespace std;

/*
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

//Interesting solution that generates only left truncatable primes in forums which would be faster

int * ESieve(int size){
	int *a=(int *)malloc(sizeof(int) * size);
	a[0] = 0;
	a[1] = 0;
	for (int i = 2 ; i < size ; i ++){
		a[i] = 1;
	}
	for(int i = 2; i < size; i++){
		if(a[i]){
			for(int j = i*2; j < size; j+=i){
				a[j] = 0;
			}
		}
	}
	return a;
}

bool isTrunc(int prime, int *a){
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
	int *a = ESieve(UPPERBOUND);
	int sum = 0, num = 0;

	for(int i = 10; i < UPPERBOUND; i++){
		if(a[i]){
			if(isTrunc(i, a)){
				sum += i;
				num ++;
				//since no clear upper bount
				if(num == 11){
					cout << "Found all 11" << endl;
					break;
				}
			}
		}
	}
	cout << "The number of truncateable primes is " << sum << endl;
}