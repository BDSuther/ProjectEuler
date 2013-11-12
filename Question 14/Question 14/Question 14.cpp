#include <iostream>
#include <map>
#include <stdint.h>

/*
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

*/

using namespace std;
map<int, int> m;

int findChain(uint64_t in){
  	int temp;
	map<int, int>::iterator it = m.find(in);
	if (it != m.end()){
		return it->second;
	} else if (in == 1){
		return 1;
	} else if (in % 2 == 0){
		temp = 1 + findChain(in/2);
		m[in] = temp;
		return temp;
	} else {
		temp = 1 + findChain(3*in + 1);
		m[in] = temp;
		return temp;
	}
	return -1;
}

int longestChain (int max){
	int maxChain = 0, len, chainNum= 0;
	for (int i = 1; i < max; i++){
		len = findChain(i);
		if (len > maxChain) {
			maxChain = len;
			chainNum = i;
		}
	}
	return chainNum;
}

int main(int argc, char* args[]){
	m[1] = 1;
	cout << "The integer with the longest chain under one million is " << longestChain(1000000) << endl;

}