/*
The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

d2d3d4=406 is divisible by 2
d3d4d5=063 is divisible by 3
d4d5d6=635 is divisible by 5
d5d6d7=357 is divisible by 7
d6d7d8=572 is divisible by 11
d7d8d9=728 is divisible by 13
d8d9d10=289 is divisible by 17
Find the sum of all 0 to 9 pandigital numbers with this property.

The best solution will most likely be constructing the numbers so lets have at it.

First thing to notice is that d6 has to be 5 or 0
if d6 is 0 then d6d7d8 divisible by 11 means d7 = d8 which doesnt follow the pandigital property so d6 must be 5

so 5d7d8 must be divisible by 11, so all the 500s divisible by 11 which gives us
506
517
528
539
550 invalid
561
572
583
594

looking at d9 we can see the valid d6d7d8d9 numbers will be
5286
5390
5728
5832

looking at d10 we can see the valid d6d7d8d9d10 numbers will be
52867 remaining 01349
53901 remaining 24678
57289 remaining 01346

d5d6d7 is divisible by 7
for 52867 only 952867 satisfies this. Remaining 0134
for 53901 none of the remaining numebers work
for 57289 only 357289 satisfies this. Remaining 0146
				  
d4 must be even
for 952867 we have 0952867 remaining 134
				   4952867 remaining 013
for 357289 we have 0357289 remaining 146
				   4357289 remaining 016
				   6357289 remaining 014

and d3d4d5 must add to a number divisible by 3 which leaves us with
30952867 remaining 14
60357289 remaining 14
06357289 remaining 14

which gives us 6 numbers

1430952867 4130952867 1460357289 4160357289 140657289 4106572989

and brute force follows

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main (int argc, char **argv){

	int pan[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
	int divisors [7] = {2, 3, 5, 7, 11, 13, 17};
	unsigned long long int count = 0;

	do{
		bool divisible = true;
		for(int i = 9; i > 2; i--){
			if((pan[i-2] * 100 + pan[i-1] * 10 + pan[i]) % divisors[i-3] != 0){
				divisible = false;
				break;
			}
		}
		if(divisible){	//the pandigital number has the right property
			unsigned int num = 0;
			for(int i = 0; i < 10; i++){
				num *= 10;
				num += pan[i];
			}
			count += num;
		}
	}while(next_permutation(pan, pan+10));
	
	cout << "The sum of the pandigital numbers is " << count << endl;
}