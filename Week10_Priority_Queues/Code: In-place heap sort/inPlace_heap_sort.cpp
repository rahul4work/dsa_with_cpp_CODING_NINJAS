/*
INPLACE HEAP SORT
level: moderate

Problem statement
Given an integer array of size N. Sort this array (in decreasing order) using heap sort.

Note: Space complexity should be O(1).

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= n <= 10^6
Time Limit: 1 sec


-----------------------------------------------------------------------------------------
Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2
-----------------------------------------------------------------------------------------
*/



#include <iostream>

#include <algorithm> 

void heapify(int arr[], int n, int i) {
    int largest = i;      
    int left = 2 * i + 1;   
    int right = 2 * i + 2;  

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {

        std::swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }

    std::reverse(arr, arr + n);
}



using namespace std;

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}



