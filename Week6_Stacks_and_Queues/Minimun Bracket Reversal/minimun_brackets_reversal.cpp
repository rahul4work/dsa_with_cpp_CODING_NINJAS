/*
MINIMUM BRACKETS REVERSAL

Problem statement
For a given expression in the form of a string, find the minimum number of brackets that can be 
reversed in order to make the expression balanced. The expression will only contain curly brackets.

If the expression can't be balanced, return -1.

Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced.
Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with the first opening
bracket and hence will not be able to make the expression balanced and the output will be -1.


Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1sec



------------------------------------------------------------------------------------------------------
Sample Input 1:
{{{
Sample Output 1:
-1
------------------------------------------------------------------------------------------------------



------------------------------------------------------------------------------------------------------
Sample Input 2:
{{{{}}
Sample Output 2:
1
------------------------------------------------------------------------------------------------------
*/



#include <iostream>
#include <string>
using namespace std;

int countBracketReversals(string input) {
	// Write your code here
    int n = input.length();

    if (n % 2 != 0) {
        return -1;
    }

    int openBrackets = 0;
    int closeBrackets = 0;

    for (int i = 0; i < n; i++) {
        if (input[i] == '{') {
            openBrackets++;
        } else {
            if (openBrackets > 0) {
                openBrackets--; 
            } else {
                closeBrackets++; 
            }
        }
    }


    return (openBrackets + 1) / 2 + (closeBrackets + 1) / 2;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}

