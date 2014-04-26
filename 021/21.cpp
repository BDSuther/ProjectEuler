#include <iostream>
#include <math.h>
#include "../PELib/PELib.h"

using namespace std;

/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; 
so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

int sumAmicable(int upperBound){
	int sum = 0;
	int dOfI;
	for (int i = 2; i <= upperBound ; i++){ 
		dOfI=PELib::properDivisorSum(i);
		if (i!=dOfI && dOfI < i && i==PELib::properDivisorSum(dOfI)){
			sum += i + dOfI;
		}
	}
	return sum;
}

int main(){
	cout << "The sum of amicable numbers below 10000 is " << sumAmicable(10000) << endl;
}
