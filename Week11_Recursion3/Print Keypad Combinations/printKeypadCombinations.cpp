/*
PRINT KEYPAD - String

Problem statement
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.


Constraints :
1 <= n <= 10^6


----------------------------------------------------------------------------------------------------------------------------
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
----------------------------------------------------------------------------------------------------------------------------
*/


#include <iostream>
#include <string>

#include <iostream>
#include <string>
using namespace std;

const string keypadMapping[] = {
    "",    "",    "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void generateCombinations(int num, string current) {
    if (num == 0) {
        cout << current << endl;
        return;
    }
    
    int digit = num % 10;
    string letters = keypadMapping[digit];
    for (char letter : letters) {
        generateCombinations(num / 10, letter + current);
    }
}

void printKeypad(int num){
    if (num == 0 || num == 1) {
        return;
    }
    
    generateCombinations(num, "");
}


using namespace std;

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}


  
