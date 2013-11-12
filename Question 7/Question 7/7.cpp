#include <iostream>

/*By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

using namespace std;

int nPrime (int nPrime){

	int a[150000]={0};

	for (int i = 2 ; i < 150000 ; i ++){
		a[i] = 1;
	}

	int primeN = 0, index = 2;

	while (primeN < nPrime) {
		index++;	
		if (a[index]){
			primeN++;
			for (int i=index*2 ; i < 150000 ; i+=index){
				a[i]=0;
			}
		}
	}

	return index;

}

int main (int argc, char*argv[]) {

	cout << "The 10001st prime is " << nPrime (10001) << endl;

}