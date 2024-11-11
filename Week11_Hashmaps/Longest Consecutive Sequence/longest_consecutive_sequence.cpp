/*
LARGEST CONSECUTIVE SEQUENCE
level: moderate

Problem statement
You are given an array of unique integers that contain numbers in random order. 
You have to find the longest possible sequence of consecutive numbers using 
the numbers from given array.

You need to return the output array which contains starting and ending element. 
If the length of the longest possible sequence is one, then the output array 
must contain only single element.

Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting 
with the number whose occurrence is earlier in the array.


Constraints :
0 <= n <= 10^6
Time Limit: 1 sec


------------------------------------------------------------------------------
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 12 
Explanation:The longest consecutive sequence here is [8, 9, 10, 11, 12]. 
So the output is the start and end of this sequence: [8, 12].
------------------------------------------------------------------------------



------------------------------------------------------------------------------
Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7 9
Explanation:There are two sequences of equal length here: [1,2,3] and [7,8,9]. 
But since [7,8,9] appears first in the array (7 comes before 1), we return this
sequence. So the output is [7,9].
------------------------------------------------------------------------------



------------------------------------------------------------------------------
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 16
Explanation:The longest consecutive sequence here is [15,16]. So the output 
is [15,16].
------------------------------------------------------------------------------
*/


#include <iostream>
#include <vector>
using namespace std;

#include <unordered_set>
#include <unordered_map>

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_set<int> numSet(arr, arr + n);
    unordered_map<int, int> indexMap;
    for (int i = 0; i < n; ++i) {
        indexMap[arr[i]] = i;
    }
    
    int maxLength = 0;
    int startElement = 0;

    for (int i = 0; i < n; ++i) {
        int num = arr[i];
        if (numSet.find(num - 1) == numSet.end()) {  // Find the start of a sequence
            int currentNum = num;
            int length = 1;

            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                length++;
            }

            if (length > maxLength) {
                maxLength = length;
                startElement = num;
            } else if (length == maxLength) {
                if (indexMap[num] < indexMap[startElement]) {
                    startElement = num;
                }
            }
        }
    }

    vector<int> result;
    if (maxLength == 1) {
        result.push_back(startElement);
    } else {
        result.push_back(startElement);
        result.push_back(startElement + maxLength - 1);
    }

    return result;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}


