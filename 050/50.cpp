#include <iostream>
#include <vector>
#include "../PELib/PELib.h"

typedef unsigned long long int uint64_t;

/*The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
*/

int main(){
	//using uint64_t because the sum of primes from 2 to primes.size() is 30 billion
	std::vector<uint64_t> primes;
	PELib::primesList(1000000, primes);
	unsigned long long int sum, consecutive = 0, prime = 0;
	
	for(size_t i = 1; i < primes.size(); i++){
		primes[i] += primes[i-1];
		if(primes[i] < 1000000 && PELib::isPrime(primes[i])){
			consecutive = i;
			prime = primes[i];
		}
	}

	for(size_t i = 1; i < primes.size(); i++){
		for(size_t j = i; j < primes.size(); j++){
			
			sum = primes[j] - primes[i];
			if(j - i > consecutive && sum > prime && PELib::isPrime(sum)){
				consecutive = j - i;
				prime = sum;
			}
			if(sum >= 1000000){ break; }
		}
	}

	std::cout << "The prime below one-million which can be written as the sum of the most consecutive primes is " << prime << ". It can be written as " << consecutive + 1 << " consecutive primes." << std::endl;
}
