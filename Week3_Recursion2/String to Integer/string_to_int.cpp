/*
STRING TO INTEGER

Problem statement
Write a recursive function to convert a given string into the number it represents. 
That is input will be a numeric string that contains only numbers, you need to convert 
the string into corresponding integer and return the answer.


Constraints :
0 < |S| <= 9
where |S| represents length of string S.


--------------------------------------------------------------------------------------
Sample Input 1 :
00001231
Sample Output 1 :
1231
--------------------------------------------------------------------------------------


--------------------------------------------------------------------------------------
Sample Input 2 :
12567
Sample Output 2 :
12567
--------------------------------------------------------------------------------------
*/


#include <iostream>
using namespace std;

int stringToNumber(char input[]) {

    if (input[0] == '\0') {
        return 0;
    }

    int digit = input[0] - '0';
    int power = 1;
    int len = 0;
    while (input[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len - 1; ++i) {
        power *= 10;
    }

    int remainingNumber = stringToNumber(input + 1);

    return digit * power + remainingNumber;

}


int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}




