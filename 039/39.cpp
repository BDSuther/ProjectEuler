#include <iostream>

using namespace std;

/*
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?
*/


int numTri (int perimeter){
	int a, b, c, sum = 0;

	a = 1;

	while(a < perimeter/3){
		b = a + 1;
		while(a + b < (perimeter/3) * 2){
			c = perimeter - a - b;
			if (a*a + b*b == c * c){
				sum ++;
			}
			b++;
		}
		a++;
	}
	return sum;
}

int main(){
	int curr, max = 0, p = 0;
	for(int i = 2; i <= 1000; i += 2){
		curr = numTri(i);
		if(curr > max){
			max = curr;
			p = i;
		}
	}
	cout << "The largest p <= 1000 that maximizes the number of right angle triangles is " << p << endl;
}
