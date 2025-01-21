/*
STAIRCASE USING DP

Problem statement
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. 
Implement a method to count how many possible ways the child can run up to the stairs. You need to 
return all possible number of ways.

Time complexity of your code should be O(n).

Since the answer can be pretty large soo print the answer with mod(10^9 +7)


Constraints :
1 <= T < = 10
1 <= N <= 10^5


--------------------------------------------------------------------------------------------------------
Sample input 1
2
2
3
Sample output 1
2
4
Explanation of sample input 1:
Test case 1:
To reach at top of 2nd stair, we have only two options i.e (2), (1,1)

Test case 2:
 To reach at top of 3rd stair, we have four options i.e (1,1,1), (1,2) ,(2,1), (3)
--------------------------------------------------------------------------------------------------------


--------------------------------------------------------------------------------------------------------
Sample input 2:
2
5
10
Sample output 2:
13
274
--------------------------------------------------------------------------------------------------------
*/


#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    // take input from the user.
    int t;
    cin >> t;
    vector<int> testCases(t);
    int maxN = 0;

    for (int i = 0; i < t; ++i) {
        cin >> testCases[i];
        if (testCases[i] > maxN) {
            maxN = testCases[i];
        }
    }

    vector<int> dp(maxN + 1, 0);

    if (maxN >= 1) dp[1] = 1;
    if (maxN >= 2) dp[2] = 2;
    if (maxN >= 3) dp[3] = 4;

    for (int i = 4; i <= maxN; ++i) {
        dp[i] = ((dp[i-1] + dp[i-2]) % MOD + dp[i-3]) % MOD;
    }

    for (int i = 0; i < t; ++i) {
        cout << dp[testCases[i]] << endl;
    }

    return 0;
}




  
