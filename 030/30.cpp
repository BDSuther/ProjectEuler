#include <iostream>

using namespace std;

/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 14 + 64 + 34 + 44
8208 = 84 + 24 + 04 + 84
9474 = 94 + 44 + 74 + 44
As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

int main(){
	int n, sumDigits, sum = 0;
	int fifthPower [10] = {0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049};
	//using 6*9^5 ~= 355000 as an upper bound since 5*9^5 gives us a 6 digit number. 999999 gives 355000 so our highest number will be under that.
	for(int i = 2; i<355000; i++){
		n = i;
		sumDigits = 0;
		while(n > 0){
			sumDigits += fifthPower[n%10];
			n = n/10;
		}
		if (sumDigits == i){
			sum+=i;
		}
	}

	cout << "The number of numbers that can be written as the sum of their digits to the fifth power is " << sum << endl;
}
		