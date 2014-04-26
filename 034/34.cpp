#include <iostream>

using namespace std;

/*
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/

int main(){
	int factorials[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
	int tmp = 0, fsum, sum = 0;

	for(int i = 3; i < factorials[9] * 6; i++){
		int tmp = i;
		fsum = 0;
		while(tmp > 0){
			fsum += factorials[tmp % 10];
			tmp /= 10;
		}
		if (fsum == i){
			sum += i;
		}
	}

	cout << "The sum of all numbers that are equal to the sum of their factorial digits is " << sum << endl;
}