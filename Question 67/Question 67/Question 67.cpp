#include <iostream>
#include <fstream>
#include <algorithm> //max

using namespace std;

/*
Find the maximum total from top to bottom of the triangle in triangle.txt
*/

int main(int argc, char* argv[]){

	ifstream file("triangle.txt");

	//since there are 15 rows, that gives us 120 numbers using 0.5n(n+1) where n is the row in the triangle
	int numbers[5051] = {0};
	int lvlNum = 0;
	//read in the triangle numbers
	for(int i = 1; i < 5051; i++){
		file >> numbers[i];
	}

	for (int level = 99; level > 0; level--){
		lvlNum = level*0.5*(level+1);
		for (int i = 0; i < level; i++){
			numbers[lvlNum - i] += max(numbers[lvlNum + level + 1 - i], numbers[lvlNum + level - i]);
		}
	}

	cout << "The maximum path is " << numbers[1] << endl;

}