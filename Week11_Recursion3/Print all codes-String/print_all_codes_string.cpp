/*
PRINT ALL CODES-String
level: hard


Problem statement
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. 
Write a program to print the list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. Just print them in different lines.

Constraints :
1 <= Length of String S <= 10



----------------------------------------------------------------------------------------------------
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
----------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string.h>
using namespace std;

void printAllPossibleCodesUtil(string input, int index, string& current) {
    if (index == input.length()) {
        cout << current << endl; 
        return;
    }

    int digit = input[index] - '0';
    char ch = 'a' + digit - 1; 
    current.push_back(ch);
    printAllPossibleCodesUtil(input, index + 1, current);
    current.pop_back(); 

    if (index + 1 < input.length()) {
        int twoDigits = stoi(input.substr(index, 2));
        if (twoDigits >= 10 && twoDigits <= 26) {
            ch = 'a' + twoDigits - 1; 
            current.push_back(ch);
            printAllPossibleCodesUtil(input, index + 2, current);
            current.pop_back(); 
        }
    }
}

void printAllPossibleCodes(string input) {
     string current = "";
    printAllPossibleCodesUtil(input, 0, current);
}


int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}

