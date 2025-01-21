/*
NUMBER OF BALANCED BTs
level: hard

Problem statement
Given an integer h, find the possible number of balanced binary trees of height h. 
You just need to return the count of possible binary trees which are balanced.

This number can be huge, so, return output modulus 10^9 + 7.

Write a simple recursive solution.

Constraints :
1 <= h <= 24

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

int balancedBTsHelper(int h, vector<int>& dp) {
    if (h <= 1) {
        return 1;
    }
    if (dp[h] != -1) {
        return dp[h];
    }
    long long int x = balancedBTsHelper(h - 1, dp);
    long long int y = balancedBTsHelper(h - 2, dp);

    dp[h] = (x * x % MOD + 2 * x * y % MOD) % MOD;
    return dp[h];
}

int balancedBTs(int h) {
    vector<int> dp(h + 1, -1);
    return balancedBTsHelper(h, dp);
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}

