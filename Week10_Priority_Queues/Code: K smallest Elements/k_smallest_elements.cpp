/*
K SMALLEST ELEMENTS
level: moderate

Problem statement
You are given with an integer k and an array of integers that contain numbers in random order. 
Write a program to find k smallest numbers from given array. You need to save them in an array and return it.

Notes :
1. Time complexity should be O(n * logk) and space complexity should not be more than O(k).
2. Order of elements in the output is not important.


Constraints:
Time Limit: 1 sec


-------------------------------------------------------------------------------------------------------------
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output 1 :
1 2 3 5 
-------------------------------------------------------------------------------------------------------------
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <queue>

vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    priority_queue<int> maxHeap;

    for (int i = 0; i < n; ++i) {

        if (maxHeap.size() < k) {
            maxHeap.push(arr[i]);
        } else {
            if (arr[i] < maxHeap.top()) {

                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }
    }

    vector<int> output;
    while (!maxHeap.empty()) {
        output.push_back(maxHeap.top());
        maxHeap.pop();
    }

    reverse(output.begin(), output.end());

    return output;
    
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;
}



