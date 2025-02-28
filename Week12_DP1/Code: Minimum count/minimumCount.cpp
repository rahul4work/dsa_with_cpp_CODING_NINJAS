/*
MINIMUM COUNT
level: medium

Problem statement
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.

That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, 
as 1 is the minimum count of numbers required to represent N as sum of squares.


Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec


--------------------------------------------------------------------------------------------------------------
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
--------------------------------------------------------------------------------------------------------------


--------------------------------------------------------------------------------------------------------------
Sample Input 2 :
9
Sample Output 2 :
1
--------------------------------------------------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

int minCount(int n)
{
	//Write your code here
	vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    // Fill dp array
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    
    return dp[n];
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}

