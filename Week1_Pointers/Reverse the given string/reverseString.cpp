/*
REVERSE THE STRING

Problem statement
You are given a string 'str' consisting of lower case alphabets. 
You have to find the reverse of the string.

For example:
If the given string is: str = "abcde". You have to print the string 
"edcba".

Constraints:
1 ≤ T ≤ 10
1 ≤ |str| ≤ 10 ^ 5 

Where |str| is the length of the string str

Time limit: 1 sec.


--------------------------------------------------------------------
Sample Input 1:
3
abcde
coding
hello1
Sample Output 1:
edcba
gnidoc
1olleh
--------------------------------------------------------------------


--------------------------------------------------------------------
Sample Input 2:
3
a
1det@Z
$1xYuP
Sample Output 2
a
Z@ted1
PuYx1$
--------------------------------------------------------------------
*/


#include<iostream>
using namespace std;

void func(char *str) 
{
    int len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    
    char reversed[len + 1]; 
    for (int i = len - 1, j = 0; i >= 0; --i, ++j) {
        reversed[j] = str[i];
    }
    reversed[len] = '\0'; 

    for (int i = 0; i <= len; ++i) {
        str[i] = reversed[i];
    }
}


int main()
{
    char ch[100001];
    int t;
    cin>>t;
    while(t--)
    {
        cin>>ch;
        func(ch);
        cout<<ch;
	cout<<endl;
    }
}


