/*
SWAP IT

Problem statement
Take two numbers as input and swap them and print the swapped 
values by using the concept of functions and pointers.

Constraints:
1 <= 'T' <= 10^2
-10^5 <= 'a', 'b' <= 10 ^ 5

Time Limit: 1 sec


---------------------------------------------------------------
Sample Input 1:
2
1 2 
3 4
Sample Output 1:
2 1
4 3
Explanation For Sample Input 1:


---------------------------------------------------------------
Sample Input 2:
2
5 6
7 8
Sample Output 2:
6 5
8 7
---------------------------------------------------------------
*/


#include <iostream>
using namespace std;

void swap(int *a,int *b)
{
	int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,b;
        cin>>a>>b;
        swap(&a , &b);
        cout<<a<<" "<<b;
        cout<<endl;
    }
}


