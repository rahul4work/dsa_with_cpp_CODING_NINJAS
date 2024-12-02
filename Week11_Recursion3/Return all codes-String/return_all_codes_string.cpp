/*
RETURN ALL CODES - String

Problem statement
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. 
Write a program to return the list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. And input string does not contain 0s.

Constraints :
1 <= Length of String S <= 10


-----------------------------------------------------------------------------------------------------
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
-----------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string.h>
using namespace std;

void getCodesHelper(string& input, int index, string& current, string output[10000], int& count) {
    if (index == input.length()) {
        output[count++] = current;
        return;
    }
    
    int singleDigit = input[index] - '0';
    if (singleDigit >= 1 && singleDigit <= 9) {
        current.push_back('a' + singleDigit - 1);
        getCodesHelper(input, index + 1, current, output, count);
        current.pop_back();
    }
    
    if (index + 1 < input.length()) {
        int doubleDigit = stoi(input.substr(index, 2));
        if (doubleDigit >= 10 && doubleDigit <= 26) {
            current.push_back('a' + doubleDigit - 1);
            getCodesHelper(input, index + 2, current, output, count);
            current.pop_back();
        }
    }
}

int getCodes(string input, string output[10000]) {
    string current;
    int count = 0;
    getCodesHelper(input, 0, current, output, count);
    return count;
}


using namespace std;

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}


