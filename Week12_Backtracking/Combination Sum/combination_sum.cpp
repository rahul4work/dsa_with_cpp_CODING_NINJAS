/*
COMBINATION SUM

Problem statement
You are given an array 'ARR' of 'N' distinct positive integers. You are also given a non-negative integer 'B'.

Your task is to return all unique combinations in the array whose sum equals 'B'. A number can be chosen any 
number of times from the array 'ARR'.

Elements in each combination must be in non-decreasing order.

For example:
Let the array 'ARR' be [1, 2, 3] and 'B' = 5. Then all possible valid combinations are-

(1, 1, 1, 1, 1)
(1, 1, 1, 2)
(1, 1, 3)
(1, 2, 2)
(2, 3)


Constraints:
1 <= 'N' <= 15
1 <= 'B' <= 20
1 <= 'ARR[i]' <= 20

Time Limit: 1sec

--------------------------------------------------------------------------------------------------------------
Sample Input 1 :
3 8
2 3 5
Sample Output 1:
Yes
Explanation Of Sample Input 1 :
All possible valid combinations are:
2 2 2 2
2 3 3
3 5
--------------------------------------------------------------------------------------------------------------



--------------------------------------------------------------------------------------------------------------
Sample Input 2 :
3 5
1 2 3 
Sample Output 2:
Yes
--------------------------------------------------------------------------------------------------------------
*/



#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

void solve(vector<vector<int>>& res, int currIndex, int currSum, vector<int>& currList, int B, vector<int>& ARR) {
    if (currSum == B) {
        res.push_back(currList);
        return;
    }
    if (currIndex == ARR.size() || currSum > B) {
        return;
    }

    for (int i = currIndex; i < ARR.size(); ++i) {
        currList.push_back(ARR[i]);
        solve(res, i, currSum + ARR[i], currList, B, ARR);
        currList.pop_back();
    }
}

vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    // Write your code here.
    sort(ARR.begin(), ARR.end()); 
    vector<vector<int>> res;
    vector<int> currList;
    solve(res, 0, 0, currList, B, ARR); 
    return res;
}

class Runner
{
    int t;

    vector<vector<int>> arr;
    vector<int> B;

public:
    void solve(vector<vector<int>> &res, int currIndex, int currSum, vector<int> &currList, int B, vector<int> &ARR)
    {
        if (currSum == B)
        {
            res.push_back(currList);
            return;
        }
        if (currIndex == ARR.size())
        {
            return;
        }

        solve(res, currIndex + 1, currSum, currList, B, ARR);

        int count = 0;
        while (currSum <= B)
        {
            count++;
            currSum += ARR[currIndex];
            currList.push_back(ARR[currIndex]);
            solve(res, currIndex + 1, currSum, currList, B, ARR);
        }

        while (count--)
        {
            currList.pop_back();
        }
    }

    vector<vector<int>> go(vector<int> &ARR, int B)
    {
        sort(ARR.begin(), ARR.end());
        vector<vector<int>> res;
        vector<int> currList;
        solve(res, 0, 0, currList, B, ARR);
        return res;
    }

    void takeInput()
    {

        t=1;
        B.resize(t);
        for (int c = 0; c < t; c++)
        {
            int n;
            cin >> n >> B[c];
            vector<int> temp(n);
            for (int i = 0; i < n; i++)
                cin >> temp[i];
            arr.push_back(temp);
        }
    }

    void execute()
    {
        for (int i = 0; i < t; i++)
        {
            vector<int> copy = arr[i];
            vector<vector<int>> res = combSum(copy, B[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<vector<int>> res = combSum(arr[i], B[i]);
            vector<vector<int>> ans = go(arr[i], B[i]);
            sort(ans.begin(), ans.end());
            sort(res.begin(), res.end());
            if (ans == res)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
};

int main()
{

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}


