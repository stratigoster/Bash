#include <iostream>
#include <cmath>
using namespace std;

void initializeMaze(char maze[63][100]) {
	cout << "initialize Maze" << endl;
	for (int i = 0; i < 63; i++) {
		for (int j = 0; j < 100; j++) {
            maze[i][j] = '_';
		}
	}
}

void printMaze(char maze[63][100]) {
	for (int i = 62; i >= 0; i--) {
		for (int j = 0; j < 100; j++) {
			cout << maze[i][j];
		}
		cout << endl;
	}
}

void printYInRegion(char maze[63][100], int startPointX, int startPointY, int distance) {
    int i = 0;
    int j = 0;

    for (i = 0; i <= distance; i++) { 
        maze[startPointX+i][startPointY] = '1';
    }

    for (j = 1; j <= distance; j++) {
        maze[startPointX+i+j-1][startPointY+j] = '1';
    }

    for (j = 1; j <= distance; j++) {
        maze[startPointX+i+j-1][startPointY-j] = '1';
    }
}

int main() {

	char maze[63][100];
    
    int n;
    cin >> n;

    int startPoint = 0;
    int distance = pow(n, 2);

    initializeMaze(maze);
            
    int startValue = 100/2;
    int cnt = 5;

    int startValueArray[] = {0,0,0,0,50}; 

    while (cnt > 1) {
        startValue -= pow(2, (cnt-1));   
        startValueArray[cnt-2] = startValue;
        cnt--;
    }

    for (int i = n; i > 0; i--) {

    	int power = pow(2, 5-i);
    	int inversePower = pow(2, i-1);
    	int xValue = 63-(4*power);
    	int length = 0;

    	for (int j = 0; j < inversePower; j++) {
    		int width = startValueArray[5-i] + power * j * 4;
    		printYInRegion(maze, xValue, width, power);
    	}
    }
    printMaze(maze);
}