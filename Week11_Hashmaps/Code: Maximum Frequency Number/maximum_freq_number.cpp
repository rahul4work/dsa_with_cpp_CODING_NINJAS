/*
MAXIMUM FREQUENCY NUMBER

Problem statement
You are given an array of integers that contain numbers in random order. 
Write a program to find and return the number which occurs the maximum
times in the given input.

If two or more elements are having the maximum frequency, return the 
element which occurs in the array first.


Constraints:
0 <= N <= 10^8
Time Limit: 1 sec


------------------------------------------------------------------------
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
------------------------------------------------------------------------


------------------------------------------------------------------------
Sample Input 2 :
6
7 2 2 4 8 4
Sample Output 2 :
2
Explanation:
Here, both element '2' and element '4' have same frequency but '2' ocurr 
first in orignal array that's why we are returning '2' as output. 
------------------------------------------------------------------------
*/



#include <iostream>
using namespace std;

#include <unordered_map>
#include <climits>

int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int, int> frequency;
    int maxFreq = 0;
    int maxFreqElement = INT_MIN;
    unordered_map<int, int> firstOccurrence;

    for (int i = 0; i < n; ++i) {
        frequency[arr[i]]++;
        if (firstOccurrence.find(arr[i]) == firstOccurrence.end()) {
            firstOccurrence[arr[i]] = i;
        }

        // Update max frequency element
        if (frequency[arr[i]] > maxFreq) {
            maxFreq = frequency[arr[i]];
            maxFreqElement = arr[i];
        } else if (frequency[arr[i]] == maxFreq) {
            if (firstOccurrence[arr[i]] < firstOccurrence[maxFreqElement]) {
                maxFreqElement = arr[i];
            }
        }
    }

    return maxFreqElement;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}


