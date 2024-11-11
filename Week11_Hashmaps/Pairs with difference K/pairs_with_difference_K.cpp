/*
PAIRS WITH DIFFERENCE K
level:moderate

Problem statement
You are given with an array of integers and an integer K. You have to find and 
print the count of all such pairs which have difference K.

Note: Take absolute difference between the elements of the array.


Constraints :
0 <= n <= 10^4
Time Limit: 1 sec



-------------------------------------------------------------------------------
Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2
Explanation
(5,2) and (1,4) are the possible combinations as their absolute difference is 3.
-------------------------------------------------------------------------------

  

-------------------------------------------------------------------------------
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
6
-------------------------------------------------------------------------------
*/


#include <iostream>
using namespace std;

#include <unordered_map>

int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
	unordered_map<int, int> frequency;
    int count = 0;

    // Populate the frequency map
    for (int i = 0; i < n; ++i) {
        frequency[arr[i]]++;
    }

    // Count pairs with difference K
    for (int i = 0; i < n; ++i) {
        frequency[arr[i]]--;  // Decrease frequency to avoid counting the same element twice

        if (frequency.find(arr[i] + k) != frequency.end()) {
            count += frequency[arr[i] + k];
        }

        if (k != 0 && frequency.find(arr[i] - k) != frequency.end()) {
            count += frequency[arr[i] - k];
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}


