#include <iostream>
#include <cstdint>
#include <set>

using namespace std;

/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

bool isPandigital(uint64_t n){
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

int main(){
	uint64_t sum, prod, numPan = 0;
	set<uint64_t> products;	//used because we are told to discard duplicate products

	for(uint64_t i = 2; i < 10; i++){
		for(uint64_t j = 1234; j < 9877; j++){
			prod = i * j;
			if (prod > 100000){ break; }
			sum = prod * 10 + i;
			sum = sum * 10000 + j;
			if(isPandigital(sum)){
				products.insert(prod);
			}
		}
	}
	for(uint64_t i = 12; i < 100; i++){
		for(uint64_t j = 123; j < 988; j++){
			prod = i * j;
			if (prod > 100000){ break; }
			sum = prod * 100 + i;
			sum = sum * 1000 + j;
			if(isPandigital(sum)){
				products.insert(prod);
			}
		}
	}
	for(set<uint64_t>::iterator it = products.begin(); it != products.end(); it++){
		numPan += *it;
	}
	cout << "The sum of all pandigital numbers is " << numPan << endl;
}