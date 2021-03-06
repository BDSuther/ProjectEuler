#include <iostream>
#include <vector>
#include <stdint.h>

/*The prime factors of 13195 are 5, 7, 13 and 29.
 
 What is the largest prime factor of the number 600851475143 ?
 */

using namespace std;

int largestPrime (uint64_t num){

	int divisor=2;

	while (divisor != num){
		if ((num % divisor)==0) {
			num = num/divisor;
		} else {
			divisor++;
		}
	}

	return divisor;

}
int main(){

	cout << "The largest prime factor of 600851475143 is " << largestPrime(600851475143) << "." << endl;

}

