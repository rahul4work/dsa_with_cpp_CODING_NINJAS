/*
Kth SMALLEST AND LARGEST ELEMENT OF ARRAY

Problem statement
You are given an array ‘Arr’ consisting of ‘N’ distinct integers and a
positive integer ‘K’. Find out Kth smallest and Kth largest element of
the array. It is guaranteed that K is not greater than the size of the array.

Example:

Let ‘N’ = 4,  ‘Arr’ be [1, 2, 5, 4] and ‘K’ = 3.  
then the elements of this array in ascending order is [1, 2, 4, 5].  Clearly, 
the 3rd smallest and largest element of this array is 4 and 2 respectively.

Constraints:
1 <= T <= 50
1 <= N <= 10^4
1 <= K <= N
-10^9 <= Arr[i] <= 10^9

Where ‘T’ is the total number of test cases, ‘N’ is the size of array ‘Arr’
and Arr[i] is the element of the given array.

Time limit: 1 sec


----------------------------------------------------------------------------
Sample Input 1:
2
4 4
5 6 7 2
4 3
1 2 5 4
Sample Output 1:
7 2 
4 2
Explanation of Sample Input 1:
Test case 1:
Here, ‘N’ = 4, ‘Arr’ = [5, 6, 7, 2] and ‘K’ = 3.
Elements of the array in ascending order are [2, 5, 6, 7]
Thus the 4rd smallest and 4rd largest elements of this array are 7 and 2
respectively.

Test case 2:
See problem statement for an explanation.
----------------------------------------------------------------------------


----------------------------------------------------------------------------
Sample Input 2:
 2
 1 1
 2
 5 1
 5 4 3 2 1
Sample Output 2:
 2 2
 1 5
----------------------------------------------------------------------------
*/



vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
    }
    std::vector<int> result(2);

    result[0] = arr[k - 1];
    result[1] = arr[n - k];

    return result;

}

int main() {
    int t;
    cin >> t;

    vector<vector<int>> arrs(t);
    vector<int> ns(t), ks(t);

    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }

        ns[i] = n;
        ks[i] = k;
        arrs[i] = arr;
    }

    for (int i = 0; i < t; ++i) {
        vector<int> result = kthSmallLarge(arrs[i], ns[i], ks[i]);
        cout << result[0] << ' ' << result[1] << '\n';
    }

    return 0;
}

