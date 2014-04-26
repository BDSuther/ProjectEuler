#ifndef __PELIB_H__
#define __PELIB_H__

#include <math.h>
#include <stdint.h>

namespace PELib {

	//modified reversing algorithm to check if a number is palindromic in any base
	bool isPalindrome(int num, int base = 10);

	//returns an integer that is a palindrom in base "base" with even or odd length (123321 even vs 12321 odd)
	int makePalindrome(int input, bool odd, int base);

	//determines if a number is prime
	bool isPrime(int n);

	//performs the sieve of eratosthenes
	void eSieve(bool *a, int size);

	//Return the sum of the proper divisors of num
	int properDivisorSum(int num);

	//Returns true if the number passed is pandigital
	bool isPandigital(uint64_t n);
	
	//Returns GCD of a and b
	int getGCD(int a, int b);
}
#endif