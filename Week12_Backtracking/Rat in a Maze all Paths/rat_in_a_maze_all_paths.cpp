/*
RAT IN A MAZE ALL PATHS
level: moderate

Problem statement
You are given a 'N' * 'N' maze with a rat placed at 'MAZE[0][0]'. Find and print 
all paths that rat can follow to reach its destination i.e. 'MAZE['N' - 1]['N' - 1]'. 
Rat can move in any direc­tion ( left, right, up and down).

Value of every cell in the 'MAZE' can either be 0 or 1. Cells with value 0 are blocked
means the rat can­not enter into those cells and those with value 1 are open.


Constraints:
1 <= N <= 10
0 <= MAZE[i][j] <=1

Where 'MAZE[i][j]' denotes the value in the cell of 'MAZE'.

Time Limit: 1 sec


-------------------------------------------------------------------------------------------
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Explanation for Sample Output 1:
Only 1 path is possible which contains coordinate < (1,1), (2,1), (3,1), (3,2) and (3,3) >

So our path matrix will look like this:

1 0 0
1 0 0
1 1 1

Which is returned from left to right and then top to bottom in one line.
-------------------------------------------------------------------------------------------



-------------------------------------------------------------------------------------------
Sample Input 2 :
2
1 0
0 1
Sample Output 2 :
 [Blank]
Explanation for Sample Output 2:
As no path is possible to the last cell, a blank vector will be returned and nothing is
printed.
-------------------------------------------------------------------------------------------
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <bits/stdc++.h> 

bool isSafe(vector<vector<int>>& maze, int x, int y, int n) {
    return (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1);
}

void findPaths(vector<vector<int>>& maze, int x, int y, int n, vector<vector<int>>& path, vector<vector<int>>& result) {
    if (x == n - 1 && y == n - 1) {
        path[x][y] = 1;
        vector<int> singlePath;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                singlePath.push_back(path[i][j]);
            }
        }
        result.push_back(singlePath);
        path[x][y] = 0; 
        return;
    }

    path[x][y] = 1;

    if (isSafe(maze, x, y + 1, n) && path[x][y + 1] == 0) {
        findPaths(maze, x, y + 1, n, path, result);
    }

    if (isSafe(maze, x + 1, y, n) && path[x + 1][y] == 0) {
        findPaths(maze, x + 1, y, n, path, result);
    }

    if (isSafe(maze, x, y - 1, n) && path[x][y - 1] == 0) {
        findPaths(maze, x, y - 1, n, path, result);
    }

    if (isSafe(maze, x - 1, y, n) && path[x - 1][y] == 0) {
        findPaths(maze, x - 1, y, n, path, result);
    }

    path[x][y] = 0;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<vector<int>> result;
    vector<vector<int>> path(n, vector<int>(n, 0));

    if (maze[0][0] == 1) {
        findPaths(maze, 0, 0, n, path, result);
    }

    return result;
}

int main()
{

  int n;
  cin >> n;
  vector<vector<int>> maze(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> maze[i][j];
    }
  }
  
  vector<vector<int>> ans = ratInAMaze(maze, n);

  // sort(ans.begin(),ans.end());

  int s = ans.size();
  for (int i = 0; i < s; i++)
  {
    int t = ans[i].size();
    for (int j = 0; j < t; j++)
    {
      cout << ans[i][j] << " ";
    }

    cout << endl;
  }
}


