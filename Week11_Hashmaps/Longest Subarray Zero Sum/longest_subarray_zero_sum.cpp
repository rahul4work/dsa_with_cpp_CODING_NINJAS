/*
LONGEST SUBARRAY ZERO SUM
level: moderate

Problem statement
Given an array consisting of positive and negative integers, find the length of the
longest subarray whose sum is zero.


Constraints:
0 <= N <= 10^8
Time Limit: 1 sec

  

------------------------------------------------------------------------------------
Sample Input 1:
10 
 95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output 1:
5
Explanation:
The five elements that form the longest subarray that sum up to zero are:
-387, -435, -5, -70, 897 
Note :You don't have to print anything. Just complete the definition of 
the function given and return the value accordingly.
------------------------------------------------------------------------------------
*/



#include <iostream>
using namespace std;

#include <unordered_map>

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    unordered_map<int, int> sumIndexMap;
    int maxLength = 0;
    int currentSum = 0;

    sumIndexMap[0] = -1; // To handle the case when sum becomes 0 at index 0

    for (int i = 0; i < n; ++i) {
        currentSum += arr[i];

        if (sumIndexMap.find(currentSum) != sumIndexMap.end()) {
            maxLength = max(maxLength, i - sumIndexMap[currentSum]);
        } else {
            sumIndexMap[currentSum] = i;
        }
    }

    return maxLength;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}


