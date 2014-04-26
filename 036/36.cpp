#include <iostream>
#include "../PELib/PELib.h"

using namespace std;

/*
The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)
*/

int main(){
	int sum = 0, input = 1, palindrome = 0;
	for(int j = 0; j < 2; j++){
		while(palindrome < 1000000){
			palindrome = PELib::makePalindrome(input, j, 10);
			//check if our base 10 palindrome is also a palindrome in base 2
			if(PELib::isPalindrome(palindrome, 2)){
				sum += palindrome;
			}
			input++;
		}
		//reset for next iteration
		input = 1; 
		palindrome = 0;
	}
	cout << "The sum of all palindromic in base 10 and 2 numbers is: " << sum << endl;
}