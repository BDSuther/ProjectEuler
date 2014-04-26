#include <iostream>
#include <vector>
#include <algorithm>
#include "../PELib/PELib.h"

using namespace std;

/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would 
be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical 
analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any 
further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

void abundants(vector<int> &abundantNum, int upperBound){
	for(int i=12; i<upperBound; i++){
		if(PELib::properDivisorSum(i) > i){
			abundantNum.push_back(i);
		}
	}
}

int abundantSum(int upperBound){
	vector<int> abundantNum;
	abundants(abundantNum, upperBound);
	int sum;

	int *a = (int*)malloc(sizeof(int) * upperBound);
	fill_n(a, upperBound, true);

	//seive our way through all the sums of the abundant numbers and set their a[sum] to 0
	for(size_t i=0; i<abundantNum.size(); i++){
		for(size_t j=i; j<=abundantNum.size(); j++){
			sum = abundantNum.at(i) + abundantNum.at(j);
			if(sum < upperBound){
				a[sum] = 0;
			} else {
				break;
			}
		}
	}

	sum = 0;
	for(int i=0; i<upperBound; i++){
		if(a[i]){
			sum += i;
		}
	}
	return sum;
}

int main(){
	cout << "The sum of all numbers below 28123 that cannot be written as the sum of 2 abundant numbers is " << abundantSum(28123) << endl;
}