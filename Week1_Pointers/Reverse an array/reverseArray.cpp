/*
REVERSE AN ARRAY

Problem statement
Given an array ar of n integers, reverse the elements of the array by 
using the concept of pointers.

Detailed explanation ( Input/output format, Notes, Images )
Constraints
1<= n <=10^6
-10^6<= ar[i] <= 10^6


---------------------------------------------------------------------
Sample Input :
4
1
2
3
4
Sample Output :
4 3 2 1 
---------------------------------------------------------------------
*/


#include <iostream>
using namespace std;

void reverse(int *ar,int n)
{
	if (n <= 1)
        return;

    int *start = ar;         
    int *end = ar + n - 1;   

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
		
        start++;
        end--;
    }
}

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    reverse(ar,n);
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    return 0;
}



