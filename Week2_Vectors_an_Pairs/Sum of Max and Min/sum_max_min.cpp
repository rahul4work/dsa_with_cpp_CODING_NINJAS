/*
SUM OF MAX AND MIN

Problem statement
You are given an array “ARR” of size N. Your task is to find out 
the sum of maximum and minimum elements in the array.

Follow Up:
Can you do the above task in a minimum number of comparisons?

Constraints:
1 <= T <= 10
1 <= N <= 10^5 
-10^9 <= ARR[i] <= 10^9

Time limit: 1 second

  
---------------------------------------------------------------
Sample Input 1:
2
7
1 2 4 5 6 6 6 
6
-1 -4 5 8 9 3
Sample Output 1:
7
5
---------------------------------------------------------------


---------------------------------------------------------------
Sample Input 2:
2
5
3 3 3 3 3 
1
-1
Sample Output 2:
6
-2
---------------------------------------------------------------
*/


#include <iostream>
#include<vector>
using namespace std;

int sumOfMaxMin(vector<int> arr, int n){

    int maxElement = INT_MIN;
    int minElement = INT_MAX;

    for (int i = 0; i < n; ++i) {
        maxElement = std::max(maxElement, arr[i]);
        minElement = std::min(minElement, arr[i]);
    }

    return maxElement + minElement;
	
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testcase;
    cin>>testcase;
    
    while(testcase--){

        int n;
        cin>>n;

        vector<int>arr(n);
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int ans = sumOfMaxMin(arr, n);

        cout<<ans<<endl;
    }
    return 0;
}


