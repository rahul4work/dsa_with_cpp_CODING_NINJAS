/*
EXTRACT UNIQUE CHARACTERS

Problem statement
Given a string S, you need to remove all the duplicates. That means, the 
output string should contain each character only once. The respective 
order of characters should remain same, as in the input string.


Constraints :
0 <= Length of S <= 10^8
Time Limit: 1 sec


--------------------------------------------------------------------------
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
--------------------------------------------------------------------------


--------------------------------------------------------------------------
Sample Input 2 :
abcde
Sample Output 2 :
abcde
--------------------------------------------------------------------------
*/


#include <iostream>
#include <string>
using namespace std;

#include <unordered_set>

string uniqueChar(string str) {
	// Write your code here
	unordered_set<char> seen;
    string result;

    for (char ch : str) {
        if (seen.find(ch) == seen.end()) {
            seen.insert(ch);
            result += ch;
        }
    }

    return result;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}


