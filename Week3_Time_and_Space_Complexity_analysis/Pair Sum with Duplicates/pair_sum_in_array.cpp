/*
PAIR SUM IN ARRAY

Problem statement
You have been given an integer array/list(ARR) and a number 'num'. 
Find and return the total number of pairs in the array/list which 
sum to 'num'.

Note:
Given array/list can contain duplicate elements. 

Constraints :
1 <= t <= 10^2
0 <= N <= 10^4
0 <= num <= 10^9

Time Limit: 1 sec


------------------------------------------------------------------
Sample Input 1:
1
9
1 3 6 2 5 4 3 2 4
7
Sample Output 1:
7
------------------------------------------------------------------


------------------------------------------------------------------
Sample Input 2:
2
9
1 3 6 2 5 4 3 2 4
12
6
2 8 10 5 -2 5
10
Sample Output 2:
0
2
------------------------------------------------------------------
*/


#include <iostream>
#include <algorithm>
using namespace std;

int pairSumHelper(int arr[], int n, int num, int index) {
    if (index == n) {
        return 0;
    }
    int count = 0;
    for (int i = index + 1; i < n; ++i) {
        if (arr[index] + arr[i] == num) {
            count++;
        }
    }

    return count + pairSumHelper(arr, n, num, index + 1);
}

int pairSum(int *arr, int n, int num)
{
	return pairSumHelper(arr, n, num, 0);
}



int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}


