#include "PELib.h"
#include <math.h>
#include <stdint.h>


namespace PELib{

	//returns true if the number is a palindrome in the specified base
	bool PELib::isPalindrome(int num, int base){
		int reverseNum = num % base;
		int i = num;

		while (i >= base){
			i = i/base;
			reverseNum *= base;
			reverseNum += i % base;
		}

		return (num == reverseNum);
	}

	//returns an integer that is a palindrom in base "base" with even or odd length (123321 even vs 12321 odd)
	int PELib::makePalindrome(int input, bool odd, int base){
		int num = input;
		int palindrome = input;
		if(odd){
			num /= base;
		}
		while(num > 0){
			palindrome *= base;
			palindrome += num % base;
			num /= base;
		}
		return palindrome;
	}

	//implementation of the sieve of eratosthenes optomized from simple implementation via wikipedia
	//Pre: boolean array all set to true, size is the size of the array - 1
	//Post: all prime indices of the array will be set to true while the others are false
	void PELib::eSieve(bool *a, int size){
		a[0] = 0;
		a[1] = 0;
		int nsqrt = (int)sqrt(size * 1.0);

		for(int i = 2; i < nsqrt; i++){
			if(a[i]){
				for(int j = i*i; j < size; j += i){
					a[j] = false;
				}
			}
		}
	}

	//Returns the sum of the proper divisors of num
	int PELib::properDivisorSum(int num){

		int sum = 1;
		int sqroot = (int)sqrt(num * 1.0);
		for(int i=2; i<=sqroot; i++){
			if (num%i == 0){
				sum += i;
				sum += num/i;
			}
		}
		//remove double count of the square root for perfect squares
		if(sqroot*sqroot == num){
			sum -= sqroot;
		}
		return sum;
	}

	//returns true if the number passed in is prime false otherwise
	bool PELib::isPrime(int n){
		if (n == 1){
			return false;
		} else if (n<4){
			return true;
		} else if (n % 2 == 0){
			return false;
		} else if (n % 3 == 0){
			return false;
		} else {
			int r = (int)floor(sqrt(n * 1.0));
			int f = 5;
			while (f<=r){
				if (n % f == 0){
					return false;
				}
				if (n % (f+2) == 0){
					return false;
				}
				f = f + 6;
			}
			return true;
		}
	}

	//returns true if the number passed is pandigital
	bool PELib::isPandigital(uint64_t n){
	int digits = 0, count = 0, tmp ;

	while(n > 0){
		tmp = digits;
		digits = digits | 1 << (int)((n % 10) - 1);

		if(tmp == digits){
			return false;
		}

		count++;
		n = n/10;
	}
	
	return digits == (1 << count) - 1;
}

	//Returns the GCD of a and b
	int PELib::getGCD(int a, int b){

    if(a > b){
        if(a % b == 0){
            return b;
        }
        else{
            b = a % b;
            PELib::getGCD(a, b);
        }
    }
    else{
        if(b % a == 0){
            return a;
        }
        else{
            a = b % a;
            PELib::getGCD(a, b);
        }
    }
	return -1;
}
}