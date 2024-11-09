/*
CHECK MAX HEAP

Problem statement
Given an array of integers, check whether it represents max-heap or not. 
Return true if the given array represents max-heap, else return false.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 10^5
1 <= Ai <= 10^5
Time Limit: 1 sec


-----------------------------------------------------------------------
Sample Input 1:
8
42 20 18 6 14 11 9 4
Sample Output 1:
true
-----------------------------------------------------------------------
*/


#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    // Write your code here
    for (int i = (n / 2) - 1; i >= 0; i--) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[i]) {
            return false;
        }

        if (right < n && arr[right] > arr[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}



