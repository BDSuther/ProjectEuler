#include "PELib.h"
#include <math.h>
#include <stdint.h>

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

int PELib::GCD(int a, int b){
	while (b != 0){
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}
