#ifndef __PELIB_H__
#define __PELIB_H__

#include <math.h>
#include <stdint.h>

namespace PELib {

	bool isPalindrome(int num, int base = 10);

	bool isPrime(int n);

	//returns an integer that is a palindrom in base "base" with even or odd length (123321 even vs 12321 odd)
	int makePalindrome(int input, bool odd, int base);

	//implementation of the sieve of eratosthenes optomized from simple implementation via wikipedia
	//Pre: boolean array all set to true, size is the size of the array - 1
	//Post: all prime indices of the array will be set to true while the others are false
	void eSieve(bool *a, int size);

	//Return the sum of the proper divisors of num
	int properDivisorSum(int num);

	//Returns true if the number passed is pandigital
	bool isPandigital(uint64_t n);
	
	int GCD(int a, int b);
}
#endif