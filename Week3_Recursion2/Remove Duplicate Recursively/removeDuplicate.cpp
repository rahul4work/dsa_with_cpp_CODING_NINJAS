/*
REMOVE DUPLICATE RECURSIVELY

Problem statement
Given a string S, remove consecutive duplicates from it recursively.


Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string


--------------------------------------------------------------------
Sample Input 1 :
aabccba
Sample Output 1 :
abcba
--------------------------------------------------------------------

--------------------------------------------------------------------
Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz
--------------------------------------------------------------------
*/


#include <iostream>
using namespace std;

void removeConsecutiveDuplicatesHelper(char *input, int index) {
    if (input[index] == '\0')
        return;

    if (input[index] == input[index + 1]) {
        int i = index;
        while (input[i] != '\0') {
            input[i] = input[i + 1];
            ++i;
        }
        removeConsecutiveDuplicatesHelper(input, index);
    } 
	else {
        removeConsecutiveDuplicatesHelper(input, index + 1);
    }
}

void removeConsecutiveDuplicates(char *input) {
  
	removeConsecutiveDuplicatesHelper(input, 0);
}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}

