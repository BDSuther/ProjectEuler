#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>

using namespace std;

/*
Euler discovered the remarkable quadratic formula:

n² + n + 41

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible 
by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.

The incredible formula  n² − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 
and 1601, is −126479.

Considering quadratics of the form:

n² + an + b, where |a| < 1000 and |b| < 1000

where |n| is the modulus/absolute value of n
e.g. |11| = 11 and |−4| = 4
Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with 
n = 0.
*/

//find primes up to 1000 for the value of B
void nPrime (vector <int>& primes){

	int a[1000] = {0};

	int index = 1;

	for(int i=0; i<1000; i++){
		index++;
		if (!a[index]){
			primes.push_back(index);
			for (int j=index*2 ; j<1000 ; j+=index){
				a[j]=1;
			}
		}
	}
}

int isPrime(int n){
	if (n == 1){
		return false;
	} else if (n<4){
		return true;
	} else if (n % 2 == 0){
		return false;
	} else if (n % 3 == 0){
		return false;
	} else {
		int r = floor(sqrt(n));
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

int findAB(vector<int> &primes){
	int maxConsecutive = 0, product = 0;
	int b;
	for(int i = 0; i < primes.size(); i++){
		b = primes.at(i);
		for(int a = -999; a < 1000; a++){
			int n = 0;
			while(isPrime(abs(n*n + a*n + b))){
				n++;
			} 
			if (n > maxConsecutive){
				maxConsecutive = n;
				product = a * b;
			}
		}
	}
	return product;
}

int main(){
	vector<int> primes;
	//find and add all primes below 1000
	nPrime(primes);
	int size = primes.size();
	//add the negative of all primes under 1000
	for(int i = 0; i < size; i++){
		primes.push_back(primes.at(i) * -1);
	}

	cout << "The product of the coefficients a and b which give the largest consecutive primes is " << findAB(primes) << endl;
}