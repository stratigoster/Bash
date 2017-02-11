#include <iostream>
using namespace std;

void initialize(char maze[63][100]) {
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

void printY(char maze[63][100], int startX, int startY, int distance, int n) {
    if (n == 0) {
        return;
    }
        
    for (int i = 0; i < distance; i++) {
        maze[startX+i][startY] = '1';
    }
    
    int temp = startX;
    temp = temp + distance - 1;
        
    for (int i = 1; i <= distance; i++) {
        maze[temp+i][startY+i] = '1';
    }

    for (int i = 1; i <= distance; i++) {
        maze[temp+i][startY-i] = '1';
    }

    printY(maze, startX+distance*2, startY - distance, distance/2, n-1);
    printY(maze, startX+distance*2, startY + distance, distance/2, n-1);
}

int main() {
    char maze[63][100];
    initialize(maze);   
    int cnt = 0; 
    cin >> cnt;
    printY(maze, 0, 50, 16, cnt);
    printMaze(maze);
}