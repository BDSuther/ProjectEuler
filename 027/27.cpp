#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include "../PELib/PELib.h"

using namespace std;

/*
Euler discovered the remarkable quadratic formula:

n² + n + 41

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible 
by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.

The incredible formula  n² − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 
and 1601, is −126479.

Considering quadratics of the form:

n² + an + b, where |a| < 1000 and |b| < 1000

where |n| is the modulus/absolute value of n
e.g. |11| = 11 and |−4| = 4
Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with 
n = 0.

alternative method to solve is using PELib::isPrime(int n) and not generating any prime list and just checking for primality with the isPrime method
*/

int findAB(bool *primes){
	int maxConsecutive = 0, product = 0;
	int b;
	int max = 0;
	for(int i = 3; i < 1000; i+=2){
		if(primes[i]){ b = i;}					//b must be positive and prime for b to be prime (n = 0)
		for(int a = -999; a < 1000; a+= 2){		//a must be odd for 1 + a + b to be odd 
			int n = 0;
			while(primes[(abs(n*n + a*n + b))]){
				n++;
			} 
			if (n > maxConsecutive){
				maxConsecutive = n;
				product = a * b;
			}
		}
	}
	return product;
}

int main(){

	bool primes[16301];			//I was using 100,000 as the sieve but after checking the maximum value of the quadratic, we can use 16300
	fill_n(primes, 16301, true);

	PELib::eSieve(primes, 16300);

	cout << "The product of the coefficients a and b which give the largest consecutive primes is " << findAB(primes) << endl;
}