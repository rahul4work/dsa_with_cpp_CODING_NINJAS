/*
RETURN KEYPAD

Problem statement
Given an integer n, using phone keypad find out all the possible strings that can
be made using digits of input n.

Return empty string for numbers 0 and 1.

Note :
1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate 
the output array and return the count of elements populated in the output array.


Constraints :
1 <= n <= 10^6


---------------------------------------------------------------------------------
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
---------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>

#include <vector>
using namespace std;

const string keypadMapping[] = {
    "",    "",    "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void generateCombinations(int num, string current, vector<string>& result) {
    if (num == 0) {
        result.push_back(current);
        return;
    }
    
    int digit = num % 10;
    string letters = keypadMapping[digit];
    for (char letter : letters) {
        generateCombinations(num / 10, letter + current, result);
    }
}

int keypad(int num, string output[]){
    if (num == 0 || num == 1) {
        return 0;
    }
    
    vector<string> result;
    generateCombinations(num, "", result);
    
    int count = 0;
    for (const string& str : result) {
        output[count++] = str;
    }
    
    return count;
}


using namespace std;

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}


