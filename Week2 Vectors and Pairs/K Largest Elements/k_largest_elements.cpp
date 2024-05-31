/*
K LARGEST ELEMENTS

Problem statement
You are given an unsorted array containing ‘N’ integers.
You need to find ‘K’ largest elements from the given array 
and fill those K elements in the given output array.

Note:
We recommend you to use inbuilt function of cpp library.
You don't need to return or print anything it has already 
been taken care of. Just implement the given function and 
fill the output array as required.

Constraints:
1 <= T <= 100
1 <= N <= 10^4  
1<= K <= N  
-10^9 <= ARR[i] <= 10^9

Where ‘T’ is the number of test cases, ‘N’ is the size of 
the array, ‘K’ is the number of elements you need to find
that are largest among the N elements.

Time Limit: 1 sec


------------------------------------------------------------
Sample Input 1:
2
4 2
3 4 2 1
5 1
2 2 3 3 1
Sample Output 1:
3 4
3
Explanation for sample input 1:
Test case 1:
If we sort the array then it will look like: [1, 2, 3, 4]. 
The 2 largest elements will be [3, 4].

Test case 2:
If we sort the array then it will look like: [1, 2, 2, 3, 3].
Then the largest element will be [3].
------------------------------------------------------------


------------------------------------------------------------
Sample Input 2:
2
5 5
0 10 1 2 2
6 2
-2 12 -1 1 20 1 
Sample Output 2:
0 1 2 2 10
12 20
------------------------------------------------------------
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Klargest(int arr[],int output[],int n,int k){

  std::make_heap(arr, arr + n);

    for (int i = 0; i < k; ++i) {
        output[k - i - 1] = arr[0]; 
        std::pop_heap(arr, arr + n - i); 
    }
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        int brr[k];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Klargest(arr, brr, n,k);
        for(int i = 0;i<k;i++){
            cout<<brr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


