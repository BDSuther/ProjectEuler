/*There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, 5C3 = 10.

In general,

nCr =	
n!
r!(n−r)!
,where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.
It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million?

We only have to find the smallest r such that nCr is bigger than 1 million.
*/

#include <iostream>

typedef unsigned long long int uint64_t;

//knuth's algorithm for n choose k
uint64_t choose(uint64_t n, uint64_t k) {
    if (k > n) {
        return 0;
    }
    uint64_t r = 1;
    for (uint64_t d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}

int main(){
	int count = 4; //nCr for n = 23 gives us 3 values bigger than 1 million
	for(int n = 24; n < 101; n++){
		int k = 2;
		while(choose(n, k) < 1000000){
			k++;
		}
		count += 2 * (n/2 - (k - 1));
		if(n % 2 == 0){ count--; }
	}

	std::cout << "The number of nCr for 1 <= n <= 100 that are greater than 1 million are " << count << std::endl;
}