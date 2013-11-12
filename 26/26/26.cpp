#include <iostream>
#include <vector>

using namespace std;

/*
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

//after reading, this can be improved by only checking primes, starting from the upperBound and stopping if the recursive cycle is of size (d-1) which is the maximum repeating cycle.

int findRC(int d){
	vector<pair <int, int> > division;
	int q, r = 1, size;
	pair<int, int> curr;
	//we will do long division with quotient and remainder to find the longest recurrance
	while(r != 0){
		r = r * 10;
		q = r/d;
		r = r - q*d;
		size = division.size();
		curr = make_pair(q, r);
		for(int i = 0; i < size; i++){
			if(curr == division.at(i)){
				return(size - i);
			}
		}
		division.push_back(curr);
	}
	return 0;
}

int findD(int upperBound){
	int longestRC = 6, d = 7, currRC;
	for(int i = 11; i < upperBound; i+=2){
		currRC = findRC(i);
		if(currRC > longestRC){
			longestRC = currRC;
			d = i;
		}
	}
	return d;
}

int main(){
	cout << "The longest recurring cycle for the value d < 1000 is " << findD(1000) << endl;
}