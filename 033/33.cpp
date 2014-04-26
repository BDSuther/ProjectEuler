#include <iostream>
#include "../PELib/PELib.h"

using namespace std;

/*
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

4 ways to represent these fractions with 1 <= n < d <= 9 and 1<= i <= 9 where i is the number we cancel out

This gives us 
1.	(10i + n)/(10i + d) = n/d	-> d = n which violates the parameters
2.	(10i + n)/(i + 10d) = n/d	-> n - i = i/9 - in/9d with i < n which leads to left hand side larger than one equaling right hand side smaller than 1 so no solutions	
3.	(i + 10n)/(10i + d) = n/d	-> i(d-n) = 9n(i-d) with d < i which gives n < d < i. This is the only form we consider since it is the only one with non-trivial answers
4.	(i + 10n)/(i + 10d) = n/d	-> d = n which violates the parameters
*/


int main(){
	int num = 1, den = 1, n, d, i;
	for(n = 1; n <= 7; n++){
		for(d = n + 1; d <= 8; d++){
			for(i = d + 1; i <= 9; i++){
				if(9 * n * (d - i) == i * (n - d)){
					num *= n;
					den *= d;
				}
			}
		}
	}

	den /= PELib::getGCD(num, den);

	cout << "The denominator is " << den << endl;
}