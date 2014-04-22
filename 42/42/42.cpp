/*
The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

cool thing I saw in the forums for this problem
char *words[] = {
#include "words.txt"
};

which makes a char* array of the words cleverly
*/

#include <iostream>
#include <fstream>
#include <cmath> //sqrt

using namespace std;

int main(int argc, char **argv){

	int count = 0;
	int sum = 0;
	int letterVal = 0;
	double x = 0;
	char letter;
	ifstream myFile("words.txt");
	if (myFile.is_open()){
		while(myFile.good()){
			myFile.get(letter);
			letterVal = letter - '@';
			if(letterVal < 0){
				if(sum != 0){
					x = (sqrt(8*sum + 1.0) - 1)/2.0;
					if(x == ((int) x)){
						count ++;
					}
					sum = 0;
				}
			} else {
				sum += letterVal;
			}
		}
	}
	myFile.close();
	cout << "The number of triangle words is " << count << "." << endl;
}