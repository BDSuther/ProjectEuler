#include <iostream>

using namespace std;

/*
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/
int getGCD(int a, int b){

    if(a > b){
        if(a % b == 0){
            return b;
        }
        else{
            b = a % b;
            getGCD(a, b);
        }
    }
    else{
        if(b % a == 0){
            return a;
        }
        else{
            a = b % a;
            getGCD(a, b);
        }
    }
}

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

	den /= getGCD(num, den);

	cout << "The denominator is " << den << endl;
}