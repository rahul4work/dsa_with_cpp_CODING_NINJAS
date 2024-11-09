/*
K LARGEST ELEMENTS
level: moderate

Problem statement
You are given with an integer k and an array of integers that contain numbers in random order. 
Write a program to find k largest numbers from given array. You need to save them in an array and return it.

Time complexity should be O(nlogk) and space complexity should be not more than O(k).

Order of elements in the output is not important.


------------------------------------------------------------------------------------------------------------
Sample Input :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output :
12
16
20
25
------------------------------------------------------------------------------------------------------------
*/


#include <iostream>
#include <vector>
using namespace std;

#include <queue>
#include <algorithm>

vector<int> kLargest(int input[], int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Iterate through the array
    for (int i = 0; i < n; ++i) {
        if (minHeap.size() < k) {
            minHeap.push(input[i]);
        } else {
            if (input[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(input[i]);
            }
        }
    }

    vector<int> output;
    while (!minHeap.empty()) {
        output.push_back(minHeap.top());
        minHeap.pop();
    }

    reverse(output.begin(), output.end());

    return output;
}


int main() {
	
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
    
    int k;
    cin >> k;
    
    vector<int> output = kLargest(input, size, k);
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << endl;
	
	return 0;
}


