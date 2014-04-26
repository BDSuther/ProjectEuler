#include <iostream>
#include "../PELib/PELib.h"

using namespace std;

/* 
	The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
*/

int main(){
	const int UPPERBOUND = 1000000;
	bool a[UPPERBOUND + 1];
	fill_n(a, UPPERBOUND + 1, true);

	PELib::eSieve(a, UPPERBOUND);

	int sum = 13, digits = 2, index, tmp;
	bool isCyclic;

	for(int i = 100; i < UPPERBOUND; i*= 10){
		digits ++; //how many digits are in our prime == how many numbers to add if cyclic
		for(int j = i; j < i * 10; j++){
			//find & check cycles
			if(a[j]){
				index = j;
				tmp;
				isCyclic = true;
				for(int k = 1; k < digits; k++){
					tmp = index % 10;
					index = index / 10;
					index += tmp * i;
					if(!a[index] || index < j){
						isCyclic = false;
						break;
					}
				}
				if(isCyclic){
					sum += digits;
				}
			}
		}
	}
	cout << "The number of cyclic primes below 1 millions is " << sum << endl;
}