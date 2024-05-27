/*
MOVE ZEROES TO END

Problem statement
Given an unsorted array of integers, you have to move the array elements in a way such that 
all the zeroes are transferred to the end, and all the non-zero elements are moved to the
front. Use the concept of dynamic memory allocation for taking array input.

All non zero element will remain in same order as before.

For example, if the input array is: [0, 1, -2, 3, 4, 0, 5, -27, 9, 0], then the output 
array must be:

[1, -2, 3, 4, 5, -27, 9, 0, 0, 0].



-------------------------------------------------------------------------------------------
Sample Input 1:
2
7
2 0 4 1 3 0 28
5
0 0 0 0 1
Sample Output 1:
2 4 1 3 28 0 0
1 0 0 0 0
-------------------------------------------------------------------------------------------


-------------------------------------------------------------------------------------------
Sample Input 2:
2
5
0 3 0 2 0
4
0 0 0 0
Sample Output 2:
3 2 0 0 0
0 0 0 0
-------------------------------------------------------------------------------------------
*/



#include<iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int *arr = new int[n];

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        int nonZeroIndex = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] != 0) {
                arr[nonZeroIndex++] = arr[i];
            }
        }

        while (nonZeroIndex < n) {
            arr[nonZeroIndex++] = 0;
        }

        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        delete[] arr;
    }

    return 0;
}


