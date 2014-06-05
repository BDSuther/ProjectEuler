/*It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
*/

#include <iostream>

typedef unsigned long long int uint64_t;

int arrToInt(int num[]){
	int toReturn = 1;
	for(int i = 0; i < 10; i++){
		toReturn = toReturn * 10 + num[i];
		num[i] = 0;
	}
	return toReturn;
}

void countDigits(uint64_t num, int digits[]){
	while(num > 0){
		digits[num % 10]++;
		num /= 10;
	}
}

int main(){
	int digits[10] = {0};
	int num, count;

	for(uint64_t i = 10; i < 1e18 - 1; i *= 10){
		for(uint64_t j = i; j < i * 10 / 6; j++){
			countDigits(j, digits);
			num = arrToInt(digits);
			count = 1;
			for(int k = 2; k < 7; k++){
				countDigits(k * j, digits);
				if(num == arrToInt(digits)){
					count++;
				} else {
					break;
				}
			}

			if(count == 6){
				std::cout << "The smallest number multiplied from 1 to 6 to contain exactly the same digits is " << j << std::endl;
				exit(0);
			}			
		}		
	}
	std::cout << "Could not find a number" << std::endl;
}