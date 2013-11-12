#include <iostream>

/*Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
 *
 *1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 *By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
 */

using namespace std;

int main(){
	int a = 2;
	int b = 8;
	int temp;
	int sum = 2;

	while (b <= 4000000){
		sum += b;
		temp = b;
		b = 4*temp + a;
		a = temp;
	}
	cout << "The sum of even Fib numbers under 1 million is " << sum << "." << endl;
}