#include <iostream>
#include <fstream>

using namespace std;
#define SIZE 20

int multMatrix(int matrix[][SIZE]){
	int maxProd = 0;
	int prod = 0;
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			
			//HORIZONTAL
			if(j<17){
				prod = matrix[i][j] * matrix[i][j+1] * matrix[i][j+2] * matrix[i][j+3];
				if (prod > maxProd){ 
					maxProd = prod;
				}
			}

			//VERTICAL
			if(i<17){
				prod = matrix[i][j] * matrix[i+1][j] * matrix[i+2][j] * matrix[i+3][j];
				if (prod > maxProd){
					maxProd = prod;
				}
			}

			//DIAGONAL LEFT
			if(j<17 && i < 17){
				prod = matrix[i][j] * matrix[i+1][j+1] * matrix[i+2][j+2] * matrix[i+3][j+3];
				if (prod > maxProd){ 
					maxProd = prod;
				}
			}

			//DIAGONAL RIGHT
			if(j>2 && i<17){
				prod = matrix[i][j] * matrix[i+1][j-1] * matrix[i+2][j-2] * matrix[i+3][j-3];
				if (prod > maxProd){ 
					maxProd = prod;
				}
			}
			
		}
		
	}
	return maxProd;
}


int main(){
	std::ifstream file("Matrix.txt");

	int matrix[SIZE][SIZE];

	for (int i = 0 ; i < SIZE ; i++){
		for (int j = 0 ; j < SIZE ; j++){
			file >> matrix[i][j];
		}
	}
	std::cout << "The largest product of 4 adjacent numbers is " << multMatrix(matrix) << ".\n";

	exit(0);
}
