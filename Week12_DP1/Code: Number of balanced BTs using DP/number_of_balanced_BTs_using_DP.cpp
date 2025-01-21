/*
NUMBER OF BALANCED BTs USING DP
level: hard

Problem statement
Given an integer h, find the possible number of balanced binary trees of height h. 
You just need to return the count of possible binary trees which are balanced.

This number can be huge, so, return output modulus 10^9 + 7.

Time complexity should be O(h).

Constraints :
1 <= h <= 10^6
  
Time Limit: 1 sec


----------------------------------------------------------------------------------
Sample Input 1:
3
Sample Output 1:
15
----------------------------------------------------------------------------------


----------------------------------------------------------------------------------
Sample Input 2:
4
Sample Output 2:
315
----------------------------------------------------------------------------------
*/


#include <iostream>
using namespace std;

#include <vector>
const int MOD = 1e9 + 7;

int balancedBTs(int h) {
    // Write your code here
    if (h == 0 || h == 1) return 1;

    vector<long long> dp(h + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= h; ++i) {
        dp[i] = (dp[i-1] * dp[i-1] % MOD + 2 * dp[i-1] * dp[i-2] % MOD) % MOD;
    }

    return dp[h];
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}



