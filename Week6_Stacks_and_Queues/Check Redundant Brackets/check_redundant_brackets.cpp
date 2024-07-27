/*
CHECK REDUNDANT BRACKETS

Problem statement
For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given that 
the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.

A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.

Example:
Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.
Note:
You will not get a partial score for this problem. You will get marks only if all the test cases are passed.
Return "false" if no brackets are present in the input.


Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1 second



--------------------------------------------------------------------------------------------------------------------
Sample Input 1:
a+(b)+c 
Sample Output 1:
true
Explanation:
The expression can be reduced to a+b+c. Hence, the brackets are redundant.
--------------------------------------------------------------------------------------------------------------------


  
--------------------------------------------------------------------------------------------------------------------
Sample Input 2:
(a+b)
Sample Output 2:
false
--------------------------------------------------------------------------------------------------------------------
*/


#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    struct Node {
        char data;
        Node* next;
        Node(char val) : data(val), next(nullptr) {}
    };
    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    ~Stack() {
        while (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    void push(char val) {
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    char top() const {
        if (topNode != nullptr) {
            return topNode->data;
        }
        return '\0'; // Return null character if stack is empty
    }

    bool empty() const {
        return topNode == nullptr;
    }
};

bool checkRedundantBrackets(string expression) {
    Stack brackets;

    for (char ch : expression) {
        if (ch == ')') {
            
            char topChar = brackets.top();
            brackets.pop();
            bool redundant = true;


            while (topChar != '(') {
                if (topChar == '+' || topChar == '-' || topChar == '*' || topChar == '/') {
                    redundant = false; 
                }
                topChar = brackets.top();
                brackets.pop();
            }

            if (redundant) {
                return true;
            }
        } else {
            brackets.push(ch);
        }
    }

    return false;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}


