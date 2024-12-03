/*
RAT IN MAZE
level: moderate

Problem statement
You are given a N*N maze with a rat placed at maze[0][0]. Find whether any path exist
that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any
direc­tion ( left, right, up and down).

Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked
means rat can­not enter into those cells and those with value 1 are open.

Constraints:
0 < N < 11 0 <= Maze[i][j] <=1

Time Limit: 1sec


-------------------------------------------------------------------------------------
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
true
-------------------------------------------------------------------------------------


-------------------------------------------------------------------------------------
Sample Input 2 :
3
1 0 1
1 0 1
0 1 1
Sample Output 2 :
 false
-------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

bool isSafe(int maze[20][20], int x, int y, int n, bool visited[20][20]) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y]);
}
bool solveMazeUtil(int maze[20][20], int x, int y, int n, bool visited[20][20]) {
    if (x == n-1 && y == n-1 && maze[x][y] == 1) {
        return true;
    }

    if (isSafe(maze, x, y, n, visited)) {
        visited[x][y] = true;

        if (solveMazeUtil(maze, x + 1, y, n, visited)) {
            return true;
        }

        if (solveMazeUtil(maze, x, y + 1, n, visited)) {
            return true;
        }

        if (solveMazeUtil(maze, x - 1, y, n, visited)) {
            return true;
        }

        if (solveMazeUtil(maze, x, y - 1, n, visited)) {
            return true;
        }

        visited[x][y] = false;
        return false;
    }

    return false;
}

bool ratInAMaze(int maze[20][20], int n) {
    bool visited[20][20] = {false};
    return solveMazeUtil(maze, 0, 0, n, visited);
}


int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  if(ratInAMaze(maze, n))
  {
	cout<<"true";
  }
  else
  {
	cout<<"false";
  }
}


