/*
RETURN SUNSETS SUM TO K
level: hard


Problem statement
Given an array A of size n and an integer K, return all subsets of A which sum to K.

Subsets are of length varying from 0 to n, that contain elements of the array. But the 
order of elements should remain same as in the input array.


Note :
The order of subsets are not important.


Constraints :
1 <= n <= 20


--------------------------------------------------------------------------------------
Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output :
3 3
5 1
--------------------------------------------------------------------------------------
*/


#include <iostream>

void findSubsets(int input[], int n, int startIndex, int currentSum, int k, int temp[], int tempSize, int output[][50], int &outputSize) {
    if (currentSum == k) {
        output[outputSize][0] = tempSize;
        for (int i = 0; i < tempSize; i++) {
            output[outputSize][i + 1] = temp[i];
        }
        outputSize++;
        return;
    }
    
    if (startIndex == n || currentSum > k) {
        return;
    }

    temp[tempSize] = input[startIndex];
    findSubsets(input, n, startIndex + 1, currentSum + input[startIndex], k, temp, tempSize + 1, output, outputSize);

    findSubsets(input, n, startIndex + 1, currentSum, k, temp, tempSize, output, outputSize);
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    int temp[50];
    int outputSize = 0;
    findSubsets(input, n, 0, 0, k, temp, 0, output, outputSize);
    return outputSize;
}


using namespace std;

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}

  
