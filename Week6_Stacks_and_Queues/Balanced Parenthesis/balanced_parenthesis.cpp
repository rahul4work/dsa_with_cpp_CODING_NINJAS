/*
CHECK IF THE BRACKETS ARE BALANCED
level : moderate

Problem statement
For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. 
Brackets are said to be balanced if the bracket which opens last, closes first.

Example:
Expression: (()())
Since all the opening brackets have their corresponding closing brackets, we say it is balanced and hence the output will be, 'true'.
You need to return a boolean value indicating whether the expression is balanced or not.

Note:
The input expression will not contain spaces in between.

Constraints:
1 <= N <= 10^7
Where N is the length of the expression.

Time Limit: 1sec


  
----------------------------------------------------------------------------------------------------------------------------------------
Sample Input 1 :
(()()())
Sample Output 1 :
true
----------------------------------------------------------------------------------------------------------------------------------------


----------------------------------------------------------------------------------------------------------------------------------------
Sample Input 2 :
()()(()
Sample Output 2 :
false

Explanation to Sample Input 2:
The initial two pairs of brackets are balanced. But when you see, the opening bracket at the fourth index doesn't have its corresponding
closing bracket which makes it imbalanced and in turn, making the whole expression imbalanced. Hence the output prints 'false'.
----------------------------------------------------------------------------------------------------------------------------------------
*/


#include <iostream>
#include <string>
using namespace std;

bool isBalanced(string expression) 
{
    // Write your code here
    int n = expression.length();
    char* stack = new char[n]; 
    int top = -1; 
    for (int i = 0; i < n; ++i) {
        char ch = expression[i];
        if (ch == '(') {
            stack[++top] = ch; 
        } else if (ch == ')') {
            if (top == -1) {
                delete[] stack; 
                return false;
            }
            --top; 
        }
    }

    bool balanced = (top == -1);
    delete[] stack; 
    return balanced;
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}


