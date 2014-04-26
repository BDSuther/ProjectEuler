#include <iostream>

using namespace std;

/*
If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
*/

int sumLetters(){

	int numbers [31] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8, 6, 6, 5, 5, 5, 7, 6, 6, 7, 8, 3}; //array of letter counts for 1 - 19, 20, 30, 40, 50, 60, 70, 80, 90, 100, 1000, and

	int num = 1, sum = 0;

	while (num < 1000){
		//adding the tens
		if (num % 100 < 20){
			sum += numbers[num%100];
		} else {
			sum += numbers[18 + (num%100)/10] + numbers[num%10];
		}
		//adding the hundreds
		if(num > 99){
			sum += numbers[num/100] + numbers[28]; //x hundred 
			if (num % 100 != 0){
				sum += numbers[30]; //and
			}
		}
		num++;
	}
	//adding the thousands
	sum += numbers[1] + numbers[29]; //one thousand

	return sum;
}

int main(int argc, char* argv[]){

	cout << "The sum of the letters in every number from 1 to 1000 inclusive is " << sumLetters() << endl;

}