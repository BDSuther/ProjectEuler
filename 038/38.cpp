#include <iostream>
#include "../PELib/PELib.h"

using namespace std;

typedef unsigned long long int uint64_t;

/*
Take the number 192 and multiply it by each of 1, 2, and 3:

192 × 1 = 192
192 × 2 = 384
192 × 3 = 576
By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?

***************************************************************************************************************************************************
Largest number MUST start with 9 since 9 * 1, 2, 3, 4, 5 gives 918273645 

91 - 98 cannot yield a 9 digit number
912 - 987 cannot yield a 9 digit number
9123 - 9876 must contain the larget 9 digit pandigital number

We can pen & paper an answer pretty easily by process of trial and error with 9xyz18abc and choosing x y z 

x must be either 2 or 3

checking the 3 first since it would be largest.

	93yz18abc remaining: 24567 

	try y = 7

	937z187bc so y can't be 7

	try y = 6

		936z187bc remaining: 245

		z can't be 5 since we get a 0 and can't be 4 since we get 8 again

		936218724 z can't be 2, y can't be 6

	y can't be 4 since we either get 8 or 9 duplicate

	try y = 2

	932z186bc remaining: 457

		try z = 7

		932718654 which is pandigital and must be the largest by contruction

Also wrote brute force program.
*/

int main(){

	uint64_t current;
	int tmp;

	for (int i = 9876; i >= 9123; i--){
		current = i;
		tmp = i * 2;
		current *= 100000;
		current += tmp;
		if (PELib::isPandigital(current)){
			break;
		}
	}

	cout << "The largest pandigital number is " << current << endl;
}

