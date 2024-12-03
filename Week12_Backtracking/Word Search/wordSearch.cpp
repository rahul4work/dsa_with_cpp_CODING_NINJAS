/*
WORD SEARCH
level: moderate

Problem statement
You are given a 2D board('N' rows and 'M' columns) of characters and a string 'word'.

Your task is to return true if the given word exists in the grid, else return false. 
The word can be constructed from letters of sequentially adjacent cells, where adjacent 
cells are horizontally or vertically neighboring.


Note:
The same letter cell should not be used more than once.


  
---------------------------------------------------------------------------------------
Sample Input 1:
coding
4 4
c z k l
o d i a
r g n m
m r s d
Sample Output 1:
true
---------------------------------------------------------------------------------------

  

---------------------------------------------------------------------------------------
Sample Input 2:
ninjas
4 4
c d k s
o d s i
d g n j
e r i n
Sample Output 2:
false
---------------------------------------------------------------------------------------
*/



#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>> &board, string &word, int x, int y, int index, int n, int m, vector<vector<bool>> &visited) {
    if (index == word.size()) {
        return true;
    }
    
    if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != word[index] || visited[x][y]) {
        return false;
    }
    
    visited[x][y] = true;
   
    bool found = dfs(board, word, x + 1, y, index + 1, n, m, visited) ||
                 dfs(board, word, x - 1, y, index + 1, n, m, visited) ||
                 dfs(board, word, x, y + 1, index + 1, n, m, visited) ||
                 dfs(board, word, x, y - 1, index + 1, n, m, visited);
    
    visited[x][y] = false; 
    
    return found;
}

bool present(vector<vector<char>> &board, string &word, int n, int m) 
{
    // Write your code here.
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == word[0] && dfs(board, word, i, j, 0, n, m, visited)) {
                return true;
            }
        }
    }
    
    return false;
}

class Runner
{
    string s;
    int n,m;
    vector<vector<char>> mat;

public:
    
    void takeInput()
    {
        cin >> s >> n >> m;
        mat = vector<vector<char>> (n,vector<char> (m));
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin >> mat[i][j];
    }
    void execute()
    {
        // make copy if vector
        auto cmat = mat;
        present(cmat,s,n,m);
    }
    void executeAndPrintOutput()
    {
        auto cmat = mat;
        if(present(cmat,s,n,m))cout << "true";
        else cout << "false";
    }
};

int main()
{
        Runner runner;
        runner.takeInput();
        runner.executeAndPrintOutput();   
    return 0;
    
}


