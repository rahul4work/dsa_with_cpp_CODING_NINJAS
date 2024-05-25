/*
FIND THE HIGHEST

Problem statement
Given an array of n integers, find and return the pointer type reference
to the highest element of the array. For example if the array is "1 2 3 4 5",
you have to return the pointer type variable holding the address of "5".


Constraints
 1<= n <=10^6
-10^6 <= ar[i] <= 10^6


-----------------------------------------------------------------------------
Sample Input 1
 2
-56 10
Sample Output 1
10
-----------------------------------------------------------------------------


-----------------------------------------------------------------------------
Sample Input 2
4
1 2 3 4
Sample Output 2
4
-----------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int* findmax(int *ar,int n)
{
    if (n == 0) 
        return nullptr;

    int *max_ptr = ar; 

    for (int i = 1; i < n; ++i) {
        if (*(ar + i) > *max_ptr)
            max_ptr = ar + i;
    }

    return max_ptr;
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
   int *ans =findmax(ar,n);
   cout<<*ans;
    
}



