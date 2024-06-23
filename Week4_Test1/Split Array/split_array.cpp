/*
SPLIT ARRAY
level: moderate

Problem statement
Given an integer array A of size N, check if the input array can be divided in two groups G1 and G2 with following properties-

- Sum of both group elements are equal
- Group 1: All elements in the input, which are divisible by 5 
- Group 2: All elements in the input, which are divisible by 3 (but not divisible by 5). 
- Elements which are neither divisible by 5 nor by 3, can be put in either group G1 or G2 to satisfy the equal sum property. 
Group 1 and Group 2 are allowed to be unordered and all the elements in the Array A must belong to only one of the groups.



Return true, if array can be split according to the above rules, else return false.



Constraints :
1 <= N <= 50



-------------------------------------------------------------------------------------------------------------------------------
Sample Input 1 :
2
1 2
Sample Output 1 :
false
-------------------------------------------------------------------------------------------------------------------------------


-------------------------------------------------------------------------------------------------------------------------------
Sample Input 2 :
3
1 4 3
Sample Output 2 :
true
-------------------------------------------------------------------------------------------------------------------------------
*/


#include <iostream>
using namespace std;

bool helper(int *arr, int n, int start, int sum1, int sum2) {
    if (start == n) {
        return sum1 == sum2;
    }

    if (arr[start] % 5 == 0) {
        return helper(arr, n, start + 1, sum1 + arr[start], sum2);
    } else if (arr[start] % 3 == 0) {
        return helper(arr, n, start + 1, sum1, sum2 + arr[start]);
    } else {
        return helper(arr, n, start + 1, sum1 + arr[start], sum2) || 
               helper(arr, n, start + 1, sum1, sum2 + arr[start]);
    }
}

bool splitArray(int *input, int size) {
    return helper(input, size, 0, 0, 0);
}


using namespace std;

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}


