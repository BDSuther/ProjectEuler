#include <iostream>
#include <math.h>

/* The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors. What is the first of these numbers?
*/

int countDistinctPrimeFactor (int num){
	int factor = 2, count = 0;
	for(int i = 2; i < (int)sqrt(num * 1.0); i++){
		if(num % i == 0){
			count++;
			while(num % i == 0){
				num /= i;
			}
		}
	}
	if (num > 1){ count ++; }
	return count;
}

bool hasFourDistinctPrimeFactor(int num){
	return countDistinctPrimeFactor(num) == 4;
}

int main(){
	int i;
	for(i = 510; i <= INT_MAX - 3; i++){ //2*3*5*17
		if(hasFourDistinctPrimeFactor(i) &&
			hasFourDistinctPrimeFactor(i + 1) &&
			hasFourDistinctPrimeFactor(i + 2) &&
			hasFourDistinctPrimeFactor(i + 3)){
				break;
		}
	}

	std::cout << "The first number of the first four consecutive integers to have four distinct prime factors is " << i << std::endl;
}