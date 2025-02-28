/*
KTH LARGEST ELEMENT
level: moderate

Problem statement
Given an array 'arr' of random integers and an integer 'k', return the kth largest element in the array.

Note: Try to do this in O(n*log k) time.

Example:
Input:
5
3 2 5 1 4
2
Output:
4
Explanation:
Array in non increasing form is [5,4,3,2,1]. So the 2nd largest is 4.


Constraints :
1 <= n <= 10^5
1 <= arr[i] <= 10^5
1 <= k <= n
Time Limit: 1 sec
  

-------------------------------------------------------------------------------------------------------
Sample Input 1 :
6
9 4 8 7 11 3
2
Sample Output 1 :
9
-------------------------------------------------------------------------------------------------------


-------------------------------------------------------------------------------------------------------
Sample Input 2 :
8
2 6 10 11 13 4 1 20
4
Sample Output 2 :
10
-------------------------------------------------------------------------------------------------------
*/


#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#include <queue>
int kthLargest(vector<int>&arr, int k) {
    // Write your code here
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < arr.size(); ++i) {

        minHeap.push(arr[i]);

        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    return minHeap.top();
}

class Runner
{
    vector<int> arr;
    int k;

public:
    void takeInput()
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            arr.push_back(x);
        }
        cin>>k;
    }

    void execute()
    {
        vector<int>arrCpy=arr;
        int ans=kthLargest(arrCpy,k);
    }

    void executeAndPrintOutput()
    {
        vector<int>arrCpy=arr;
        int ans=kthLargest(arrCpy,k);
        cout<<ans;
    }
};
int main()
{
    // freopen("./Testcases/large/in/input12.txt", "r", stdin);
    // freopen("./Testcases/large/out/output12.txt", "w", stdout);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}



