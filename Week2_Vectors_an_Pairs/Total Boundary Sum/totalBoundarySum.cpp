/*
TOTAL BOUNDARY SUM

Problem statement
For a given two-dimensional square matrix of size (N x N). 
Find the total sum of elements on both the diagonals and 
at all the four boundaries.

Constraints:
0 <= N <= 10^3
0 <= input[i][j] <10
Time Limit: 1sec


----------------------------------------------------------
Sample input 1:
3
1 2 3
4 5 6
7 8 9
Sample Output 1:
45
----------------------------------------------------------

  
----------------------------------------------------------
Sample input 2:
5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
Sample Output 2:
273
----------------------------------------------------------
*/

#include <iostream>
#include<vector>
using namespace std;

int totalSum(vector<vector<int>> input, int n)
{
    if (n == 0) return 0;

    int sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += input[0][i]; 
        sum += input[n - 1][i]; 
        if (i != 0 && i != n - 1) { 
            sum += input[i][0]; 
            sum += input[i][n - 1]; 
        }
    }

    for (int i = 0; i < n; ++i) {
        sum += input[i][i]; 
        sum += input[i][n - i - 1]; 
    }

    if (n % 2 != 0) {
        sum -= input[n / 2][n / 2];
    }

    sum -= input[0][0] + input[0][n - 1] + input[n - 1][0] + input[n - 1][n - 1];

    return sum;
}


int main()
{
	
		int n;
		cin >> n;
		vector<vector<int>> arr(n,vector<int>(n));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
        
        cout << totalSum(arr, n) << endl; 
	
}


