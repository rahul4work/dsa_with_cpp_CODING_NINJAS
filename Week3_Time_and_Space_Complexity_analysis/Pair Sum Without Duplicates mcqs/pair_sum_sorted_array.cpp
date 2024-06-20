/*
PAIR SUM IN SORTED ARRAY

Problem statement
You have been given a sorted integer array/list(ARR) and a number 'num'. 
Find and return the total number of pairs in the array/list which sum to 'num'.

Note:
Given array/list can not contain duplicate elements. 

Constraints :
0 <= N <= 10^6
0 <= num <= 10^6
Time Limit: 1 sec


--------------------------------------------------------------------------------
Sample Input 1:
5
1 2 3 4 5
7
Sample Output 1:
2
--------------------------------------------------------------------------------


--------------------------------------------------------------------------------
Sample Input 2:
5
1 2 3 4 5
10
Sample Output 2:
0
--------------------------------------------------------------------------------
*/


#include <iostream>
using namespace std;

int pairSum(int A[], int size, int K)
{

    int count = 0;

    int left = 0;
    int right = size - 1;

    while (left < right) {
        int sum = A[left] + A[right]; 

        if (sum == K) {
            count++;
            left++;
            right--;
        }

        else if (sum < K) {
            left++;
        }
  
        else {
            right--;
        }
    }

    return count;
}

int main()
{
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    int k;
    cin>>k;
    int ans = pairSum(input, n, k);
    cout<<ans;
    return 0;
}

