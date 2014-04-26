#include <iostream>
#include <algorithm>
#include "../PELib/PELib.h"

/*By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

using namespace std;

int nPrime (int nPrime){

	bool a[150001];
	std::fill_n(a, 150001, true);
	PELib::eSieve(a, 150000);

	int primeN = 0;

	for(int i = 0; i < 150000; i++){
		if(a[i]){
			primeN++;
		}
		if (primeN == nPrime){
			return i;
		}
	}

	return -1;

}

int main (int argc, char*argv[]) {

	cout << "The 10001st prime is " << nPrime (10001) << endl;

}