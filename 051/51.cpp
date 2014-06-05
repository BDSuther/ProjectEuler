#include <iostream>
#include "../PELib/PELib.h"

/*By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.

Analysis:

We can see right away that the repeated number must be 0, 1, or 2 since a repeated number larger than that percludes any 8 prime value families

Since prime, the last digit cannot be one of the repeated digits and it must be of the set {1, 3, 7, 9}

To determine how many digits are repeated in our number we can use the handy dandy property of numbers that if the sum of their digits is divisible by 3, the number itself is divisible by 3

Assuming that the number is probably a 5 or 6 digit number

The following table shows how many numbers are divisible by 3 depending on the mod of the sum of the non-repeated numbers.

For example if 2 digits are repeated then (sum of the non-repeating digits) % 3 can be 0 1 or 2. When it is 0 then adding 2*(repeating digit) for (digit = 0 .. 9) gives us 4 values for a which (2*digit + 0) % 3 = 0. 
If the mod of the sum of non-repeating digits is 1 then for 2*(repeating) for (repeating = 0 .. 9) we get 3 values for which (2*repeating + 1) % 3 = 0, and for non-repeating 2 we also get 3 values for which 
(2*repeating + 2)% 3 = 0 which means no numbers with 2 repeating numbers can be a memeber of the 8 prime family.

continuing in this fashion we get the following table (for up to 6 digit numbers)
		
		repeated digits
		2	3	4	5
	0	4	10	4	4	
mod	1	3	0	3	3
	2	3	0	3	3

this shows us that our 8 prime family prime MUST have 3 repeating digits.

So, each prime must follow one of the following forms

for 5-digit numbers
a a a b c
a a b a c
a b a a c
b a a a c

where a can have values (0 .. 2)
b can have values (0 .. 9)
and c can have values (1, 3, 7, 9)

additionally (b + c) % 3 != 0 and b, c != a

for 6-digit primes we have the following
a a a b c d
a a b a c d
a a b c a d
a b a a c d
a b a c a d
a b c a a d
b a a a c d
b a a c a d
b a c a a d
b c a a a d

where a can have values (0 .. 2)
b, c can have values (0 .. 9)
and d can have values (1, 3, 7, 9)

additionally (b + c + d) % 3 != 0 and b, c, d != a

Using this information, we can construct numbers and then test for primality.

Hard to ensure smallest to largest number construction, easiest way is to just make all the numbers

This solution is a very *specific* solution and wouldn't work for finding/testing for n-prime families in a range 
*/

int arrToInt(int num[], int numDigits){
	int toReturn = 0;
	for(int i = 0; i < numDigits; i++){
		toReturn = toReturn * 10 + num[i];
	}
	return toReturn;
}


//Will go through the 'mask' of 5 or 6 digit numbers and see if any are in an eight prime family
void checkNum(int *mask[], int digits, int last, int &currSmallest){
	int currNum = 0;
	int tmp, numDigits, numPatterns, candidate;
	int num[6] = {0};
	int repeatedStart = 0;
	int numPrimes = 0;

	numDigits = (digits < 10) ? 5 : 6;
	numPatterns = (numDigits == 5) ? 4 : 10;

	for(int pattern = 0; pattern < numPatterns; pattern++){ //going through all the orders in the arrays
		if(mask[pattern][0] == 1){
			repeatedStart = 1;
		} else {
			repeatedStart = 0;
		}

		tmp = digits;
		for(int digit = numDigits - 2; digit >= 0; digit--){ //going from the back so we dont have to figure out the first digit of 'digits' and can instead just mod by 10 and divide by 10
			if(mask[pattern][digit] == 1){
				num[digit] = repeatedStart;
			} else {
				num[digit] = tmp % 10;
				tmp /= 10;
			}
		}

		num[numDigits - 1] = last;
		currNum = arrToInt(num, numDigits);
		// number is ready to test now.
		numPrimes = 0;
		candidate = 0;
		if(currNum < currSmallest){
			if(PELib::isPrime(currNum)){ 
				numPrimes++;
				candidate = currNum;
			}

			for(int i = repeatedStart + 1; i < 10 && numPrimes >= i - 2; i++){
				for(int digit = 0; digit < numDigits - 1; digit++){ //going from the back so we dont have to figure out the first digit of 'digits' and can instead just mod by 10 and divide by 10
					if(mask[pattern][digit] == 1){
							num[digit] = i;
					}
				}
				currNum = arrToInt(num, numDigits);
				if(PELib::isPrime(currNum)){
					numPrimes++;
					if(candidate == 0){ candidate = currNum; }
				}
			}
		}
		if(numPrimes == 8){
			currSmallest = candidate;
		}
	}
}


int main(){
	int smallestEightFamilyNum = 1000000;
	int currentNum = 0;

	int f1[4] = {1, 1, 1, 0};
	int f2[4] = {1, 1, 0, 1};
	int f3[4] = {1, 0, 1, 1};
	int f4[4] = {0, 1, 1, 1};

	int *fives[4] = {f1, f2, f3, f4};

	int s1[5] = {1, 1, 1, 0, 0};
	int s2[5] = {1, 1, 0, 1, 0};
	int s3[5] = {1, 1, 0, 0, 1};
	int s4[5] = {1, 0, 1, 1, 0};
	int s5[5] = {1, 0, 1, 0, 1};
	int s6[5] = {1, 0, 0, 1, 1};
	int s7[5] = {0, 1, 1, 1, 0};
	int s8[5] = {0, 1, 1, 0, 1};
	int s9[5] = {0, 1, 0, 1, 1};
	int s10[5] = {0, 0, 1, 1, 1};

	int *sixes[10] = {s1, s2, s3, s4, s5, s6, s7, s8, s9, s10};

	int **numDigits = fives;

	int last[4] = {1, 3, 7, 9};

	for(int i = 1; i < 100; i++){   //this determines the '0' values in the arrays
		if(i>9){ numDigits = sixes; } //constructing 6 digit numbers
		for(int j = 0; j < 4; j++){ //cycling through the last digit
			if(((i % 10) + (i/10) + last[j]) % 3 != 0){   //The number won't be divisible by 3
				checkNum(numDigits, i, last[j], smallestEightFamilyNum);
			}
		}
	}
	std::cout << "The smallest number that is part of an 8 prime family is " << smallestEightFamilyNum << std::endl;
}


