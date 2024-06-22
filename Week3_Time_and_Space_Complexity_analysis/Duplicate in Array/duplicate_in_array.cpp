/*
DUPLICATE IN ARRAY

Problem statement
You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). 
Each number is present at least once. That is, if N = 5, the array/list constitutes values ranging 
from 0 to 3, and among these, there is a single integer value that is present twice. You need to find 
and return that duplicate number present in the array.


Constraints :
1 <= t <= 10^2
0 <= N <= 10^6

Time Limit: 1 sec



-----------------------------------------------------------------------------------------------------
Sample Input 1:
1
9
0 7 2 5 4 7 1 3 6
Sample Output 1:
7
-----------------------------------------------------------------------------------------------------


-----------------------------------------------------------------------------------------------------
Sample Input 2:
2
5
0 2 1 3 1
7
0 3 1 5 4 3 2
Sample Output 2:
1
3
-----------------------------------------------------------------------------------------------------
*/



#include <iostream>
using namespace std;

int findDuplicate(int *arr, int n)
{
    //Write your code here
    int zeroCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            zeroCount++;
            if (zeroCount > 1) {

                return 0;
            }
            continue; 
        }
        int index = abs(arr[i]); 
        if (arr[index] < 0) {
            return index;
        }
        arr[index] = -arr[index];
    }

    return -1;
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}

