#include <iostream>

using namespace std;

/*
In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?
*/

int main(){
	int coins[8] = { 1, 2, 5, 10, 20, 50, 100, 200 };
	int ways[201] = {0};
	ways[0] = 1;

	for(int i = 0; i < 8; i++){
		for(int j = coins[i]; j < 201; j++){
			ways[j] += ways[j - coins[i]];
		}
	}
	cout << "There are " << ways[200] << " to make 2 pounds out of coins." << endl;
}