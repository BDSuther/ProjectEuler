#include <iostream>

/*A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.
 *
 *Find the largest palindrome made from the product of two 3-digit numbers.
 */

bool isPal(int num){
	int reverseNum = num%10;
	int i = num;

	while (i>10){
		i = i/10;
		reverseNum *=10;
		reverseNum += i%10;
	}

	return (num == reverseNum);
}

int largestPal(int nLength){

	int highest = 9;
	int highestPal = 0;
	int iterator, product;

	for (int i = 1; i < nLength; i++){
		highest *= 10;
		highest += 9;
	}

	int lowest = 10^(nLength-1);

	while (highest >= lowest){
		iterator = highest;

		while (iterator >= lowest){
			product = iterator * highest;

			if (isPal(product)){
				if (product > highestPal){
					highestPal = product;
				}
			}
			iterator--;
		}
		highest--;
	}

	return highestPal;
}

int main(){

	std::cout << "The largest palindrome made from the product of two 3-digit numbers is " << largestPal(3) << ".\n";

}
