/*
SUM OF DIGITS (RECURSIVE)

Problem statement
Write a recursive function that returns the sum of the digits of a given integer.


Constraints :
0 <= N <= 10^9


----------------------------------------------------------------------------------
Sample Input 1 :
12345
Sample Output 1 :
15
----------------------------------------------------------------------------------


----------------------------------------------------------------------------------
Sample Input 2 :
9
Sample Output 2 :
9
----------------------------------------------------------------------------------
*/

#include <iostream>
#include "solution.h"
using namespace std;

int sumOfDigits(int n) {
    // Write your code here

    if (n < 10) {
        return n;
    }
    int lastDigit = n % 10;
    int sumOfRest = sumOfDigits(n / 10);
    
    return lastDigit + sumOfRest;
}


int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
