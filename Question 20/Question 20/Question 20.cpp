#include <iostream>

using namespace std;

/*
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

void factorial(int *a, int start){
	for(int i=2; i<=start; i++){
		//multiply
		for(int j=0; j<201; j++){
			a[j] *= i;
		}
		//shift
		for(int j=0; j<200; j++){
			a[j+1] += a[j]/10;
			a[j] = a[j]%10;
		}
	}
}

int main(){
	int a[201] = {0};
	a[0] = 1;
	int sum = 0;

	factorial(a, 100);

	for(int i=0; i<201; i++){
		sum += a[i];
	}
	cout << "The sum of the digits in 100! is " << sum << endl;
}
