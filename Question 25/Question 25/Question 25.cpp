#include <iostream>

using namespace std;

/*
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the first term in the Fibonacci sequence to contain 1000 digits?
*/

int fib(int *fib1, int *fib2){
	int iteration = 1, max;

	while (true){
		max = fib1[0];
		for(int i=1; i<=max; i++){
			fib2[i] += fib1[i];
			fib2[i+1] += fib2[i]/10;
			fib2[i] = fib2[i]%10;
		}
		iteration++;
		if(fib2[fib2[0]+1]){
			fib2[0]++;
			if(fib2[0] == 1000){
				break;
			}
		}

		max = fib2[0];
		for(int i=1; i<=max; i++){
			fib1[i] += fib2[i];
			fib1[i+1] += fib1[i]/10;
			fib1[i] = fib1[i]%10;
		}
		iteration++;
		if(fib1[fib1[0]+1]){
			fib1[0]++;
			if(fib1[0] == 1000){
				break;
			}
		}
	}
	return iteration;
}

int main(){
	//we're using the 0 index of both fib numbers to keep track of the upperbound
	int fib1[1001] = {0}, fib2[1001] = {0};
	fib1[0] = 1;
	fib1[1] = 1;

	cout << "The first fib term to contain 1000 digits is " << fib(fib1, fib2) << endl;
}