#include <iostream>
#include "../PELib/PELib.h"


/*It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/

int main(){
	bool a[10001];
	bool found = false;
	int prime, i;
	
	std::fill_n(a, 10001, true);
	PELib::eSieve(a, 10000);

	int num = 33;
	while(!found){
		num += 2;
		if(!a[num]){
			found = true;
			for(i = 1; 2*i*i <= num; i++){
				if(a[num - (2*i*i)]){
					found = false;
					break;
				}
			}					
		}
	}

	std::cout << "The first odd composite to violate the proposal is " << num << std::endl;
}