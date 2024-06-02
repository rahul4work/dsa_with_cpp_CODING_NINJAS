/*
Problem statement
Given an array/list 'ARR' of integers and a position ‘M’. You have
to reverse the array after that position.

Example:

We have an array ARR = {1, 2, 3, 4, 5, 6} and M = 3 , considering 0 
based indexing so the subarray {5, 6} will be reversed and our 
output array will be {1, 2, 3, 4, 6, 5}.

Constraints:
1 <= T <= 10
0 <= M <= N <= 5*10^4
-10^9 <= ARR[i] <= 10^9

Time Limit: 1 sec


-------------------------------------------------------------------
Sample Input 1:
2
6 3
1 2 3 4 5 6
5 2
10 9 8 7 6
Sample Output 1:
1 2 3 4 6 5
10 9 8 6 7
-------------------------------------------------------------------


-------------------------------------------------------------------
Sample Input 2:
2
7 3
1 4 5 6 6 7 7 
9 3
10 4 5 2 3 6 1 3 6
Sample Output 2:
 1 4 5 6 7 7 6
 10 4 5 2 6 3 1 6 3 
-------------------------------------------------------------------
*/


void reverseArray(vector<int> &arr , int m) {
  
    int left = m + 1;
    int right = arr.size() - 1;
    
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
          	
}

