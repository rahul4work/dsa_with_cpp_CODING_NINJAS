/*
QUICK SORT
level: moderate

Problem statement
Given the 'start' and the 'end'' positions of the array 'input'. 
Your task is to sort the elements between 'start' and 'end' using quick sort.


Note :
Make changes in the input array itself.

Constraints :
1 <= N <= 10^3
0 <= input[i] <= 10^9
  
-----------------------------------------------------------------------------
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
-----------------------------------------------------------------------------

-----------------------------------------------------------------------------
Sample Input 2 :
5
1 2 3 5 7
Sample Output 2 :
1 2 3 5 7 
-----------------------------------------------------------------------------
*/


#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;


int partitionArray(int input[], int start, int end) {
	// Write your code here

	int pivot = input[end]; 
    int partitionIndex = start; 

    for (int i = start; i < end; ++i) {
        if (input[i] <= pivot) {
            int temp = input[i];
            input[i] = input[partitionIndex];
            input[partitionIndex] = temp;

            partitionIndex++;
        }
    }

    int temp = input[partitionIndex];
    input[partitionIndex] = input[end];
    input[end] = temp;

    return partitionIndex;

}

void quickSort(int input[], int start, int end) {

	if (start < end) {
        int partitionIndex = partitionArray(input, start, end);
        quickSort(input, start, partitionIndex - 1);
        quickSort(input, partitionIndex + 1, end);
    }
}

int main() {
  
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int* input = new int[n];
    for (int i = 0; i < n; i++) {
        input[i] = v[i];
    }

    quickSort(input, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << input[i] << ' ';
    }
    cout << '\n';

    delete[] input;

}



