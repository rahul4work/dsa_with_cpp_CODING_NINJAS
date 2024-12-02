/*
CHECK AB
level: moderate

Problem statement
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function 
that checks if the string was generated using the following rules:

a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.


Constraints :
1 <= |S| <= 1000
where |S| represents length of string S.


-----------------------------------------------------------------------------------------
Sample Input 1 :
abb
Sample Output 1 :
true
Sample Input 2 :
abababa
Sample Output 2 :
false
Explanation for Sample Input 2
In the above example, a is not followed by either "a" or "bb", instead it's followed by 
"b" which results in false to be returned.
-----------------------------------------------------------------------------------------
*/



#include <iostream>

bool checkABHelper(char input[], int index) {
    if (input[index] == '\0') {
        return true;
    }
    
    if (input[index] == 'a') {
        if (input[index + 1] == 'a' || input[index + 1] == '\0') {
            return checkABHelper(input, index + 1);
        }
        if (input[index + 1] == 'b' && input[index + 2] == 'b') {
            return checkABHelper(input, index + 3);
        }
    }
    if (input[index] == 'b' && input[index + 1] == 'b') {
        if (input[index + 2] == 'a' || input[index + 2] == '\0') {
            return checkABHelper(input, index + 2);
        }
    }
    return false;
}


bool checkAB(char input[]) {
    if (input[0] != 'a') {
        return false;
    }
    return checkABHelper(input, 0);
}



using namespace std;

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}

