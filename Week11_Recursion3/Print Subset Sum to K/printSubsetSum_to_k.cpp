/*
PRINT SUBSETS SUM TO K
level: hard


Problem statement
Given an array A and an integer K, print all subsets of A which sum to K.

Subsets are of length varying from 0 to n, that contain elements of the array.
But the order of elements should remain same as in the input array.


Note :
The order of subsets are not important. Just print them in different lines.


-----------------------------------------------------------------------------
Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output:
3 3
5 1
-----------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

#include <vector>

void printSubsetSumToKUtil(int input[], int n, int index, int currentSum, int k, vector<int>& subset) {
    // Base case: If index reaches the end of array
    if (index == n) {
 
        if (currentSum == k) {
            for (int i = 0; i < subset.size(); ++i) {
                if (i > 0) cout << " ";
                cout << subset[i];
            }
            cout << endl;
        }
        return;
    }

    subset.push_back(input[index]);
    printSubsetSumToKUtil(input, n, index + 1, currentSum + input[index], k, subset);

    subset.pop_back();
    printSubsetSumToKUtil(input, n, index + 1, currentSum, k, subset);
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    vector<int> subset;
    printSubsetSumToKUtil(input, size, 0, 0, k, subset);
}


int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}


