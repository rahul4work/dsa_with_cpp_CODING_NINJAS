/*
TRIPLET SUM
level: moderate

Problem statement
You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the 
array/list which sum to X.

Note :
Given array/list can contain duplicate elements.


Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= X <= 10^9

Time Limit: 1 sec

  

-----------------------------------------------------------------------------------------------------------
Sample Input 1:
1
7
1 2 3 4 5 6 7 
12
Sample Output 1:
5
-----------------------------------------------------------------------------------------------------------


-----------------------------------------------------------------------------------------------------------
Sample Input 2:
2
7
1 2 3 4 5 6 7 
19
9
2 -5 8 -6 0 5 10 11 -3
10
Sample Output 2:
0
5
-----------------------------------------------------------------------------------------------------------
*/



#include <iostream>
#include <algorithm>
using namespace std;

int tripletSum(int *arr, int n, int num)
{
	//Write your code here
    sort(arr, arr + n);
    int count = 0;

    for (int i = 0; i < n - 2; i++) {
        int target = num - arr[i];
        int startIndex = i + 1;
        int endIndex = n - 1;

        while (startIndex < endIndex) {
            int sum = arr[startIndex] + arr[endIndex];
            if (sum < target) {
                startIndex++;
            } else if (sum > target) {
                endIndex--;
            } else {
                if (arr[startIndex] == arr[endIndex]) {
                    int elementsCount = endIndex - startIndex + 1;
                    count += (elementsCount * (elementsCount - 1)) / 2;
                    break;
                }

                int startCount = 1, endCount = 1;

                while (startIndex + 1 < endIndex && arr[startIndex] == arr[startIndex + 1]) {
                    startIndex++;
                    startCount++;
                }

                while (endIndex - 1 > startIndex && arr[endIndex] == arr[endIndex - 1]) {
                    endIndex--;
                    endCount++;
                }

                count += startCount * endCount;
                startIndex++;
                endIndex--;
            }
        }
    }

    return count;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}



