#include <iostream>
#include <stdint.h>
using namespace std;
/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.


How many such routes are there through a 20×20 grid?

*/

uint64_t calcRoutes(int length){
	length++;
	uint64_t *grid = new uint64_t [length * length];
	//grid[i][j] is equivalent to grid[i*length+j]
	uint64_t routes = 0;
	//south and right edge are 1 
	for(int j = 0 ; j<length; j++){
		grid[(length-1)*length+j] = 1;
		grid[j*length+length-1] = 1;
	}
	//all other columns adding the cell below and to the right of the current column eventually ending at grid[0][0]
	for(int i = length-2; i>=0; i--){
		for(int j=length-2; j>=0; j--){
			grid[i*length+j] = grid[i*length+j+1] + grid[(i+1)*length+j];
			if (grid[i*length+j] < 0){
				cout << grid[i*length+j] << " " << i << " " << j << endl;
			}
		}
	}

	routes = grid[0];
	
	//memory cleanup
	delete [] grid;

	return routes;
}

int main(int argc, char* argv[]){

	cout << "The number of routes from the top left to bottom right corner of a 20x20 grid is " << calcRoutes(20) << endl;

}