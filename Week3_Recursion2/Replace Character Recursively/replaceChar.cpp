/*
REPLACE CHARACTER RECURSIVELY

Problem statement
Given an input string S and two characters c1 and c2, you 
need to replace every occurrence of character c1 with character
c2 in the given string.

Do this recursively.


Constraints :
1 <= Length of String S <= 10^6


---------------------------------------------------------------
Sample Input :
abacd
a x
Sample Output :
xbxcd
---------------------------------------------------------------
*/


#include <iostream>
using namespace std;

void replaceCharacterHelper(char input[], char c1, char c2, int index) {
    
    if (input[index] == '\0')
        return;

    if (input[index] == c1)
        input[index] = c2;

    replaceCharacterHelper(input, c1, c2, index + 1);
}


void replaceCharacter(char input[], char c1, char c2) {
   
     replaceCharacterHelper(input, c1, c2, 0);
    
}

int main() {
    char input[1000000];
    char c1, c2;
    cin >> input;
    cin >> c1 >> c2;
    replaceCharacter(input, c1, c2);
    cout << input << endl;
}

