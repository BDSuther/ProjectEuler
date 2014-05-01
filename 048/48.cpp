#include <iostream>

typedef unsigned long long int uint64_t;

/*The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.

note, we only need the last 10 digits so we can mod the number by 1000000000 every time we multiply
*/

int main(){
	uint64_t modBy = 10000000000, sum = 0, pow = 1, num;
	while(pow <= 1000){
		num = 1;
		for(int i = 1; i <= pow; i++){
			num *= pow;
			num = num % modBy;
			//if(num == 0 && i != pow){ num = 1; } //to account for num having to trailing 0s but not at the end of
		}
		sum += num;
		pow++;
	}
	sum = sum % modBy;
	std::cout << "The sume of x^x for x = 1 to 1000 is " << sum << std::endl;
}
