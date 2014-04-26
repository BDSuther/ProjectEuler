#include <iostream>

/*A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

int main(){

	int a = 1;
	int b = 2;

	while (a < 333){
		b = a+1;
		while ((a + b) <= 665){
			if ((a*a + b*b) == (1000 - a - b)*(1000 - a - b)){
				std::cout << "The product is " << a*b*(1000 - a - b) << ".\n";
				exit(0);
			}
			b++;
		}
		a++;
	}
}