/*
PRINT PERMUTAIONS
level: moderate

Problem statement
Given an input string (STR), print all possible permutations of the input string.

Note:
The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.



----------------------------------------------------------------------------------------------
Sample Input 1:
cba
Sample Output 1:
abc
acb
bac
bca
cab
cba
----------------------------------------------------------------------------------------------
*/


#include <iostream>
#include <string>
using namespace std;

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void generatePermutations(string input, int start, int end) {
    if (start == end) {
        cout << input << endl;
    } else {
        for (int i = start; i <= end; i++) {
            swap(input[start], input[i]);
            generatePermutations(input, start + 1, end);
            swap(input[start], input[i]); // backtrack
        }
    }
}

void printPermutations(string input){
	generatePermutations(input, 0, input.length() - 1);
}


int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}


