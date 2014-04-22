#include <iostream>

bool IsPandigital(long n)
    {
        int digits = 0; int count = 0; int tmp;

        for (; n > 0; n /= 10, ++count)
        {
            if ((tmp = digits) == (digits |= 1 << (n - ((n / 10) * 10) - 1)))
                return false;
        }

        return digits == (1 << count) - 1;
    }

int main(){
    int pans = 0;
	for (int i = 123456789; i <= 123987654; i++)
    {
        if (IsPandigital(i))
        {
            pans++;
        }
    }
	if(IsPandigital(129384756)){
		std::cout <<  "asdasda";
	}
	std::cout << pans;
}
