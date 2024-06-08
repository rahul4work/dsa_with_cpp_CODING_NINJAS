/*
COUNT ZEROS

Problem statement
Given an integer N, count and return the number of zeros that are
present in the given integer using recursion.


Constraints :
0 <= N <= 10^9


-------------------------------------------------------------------
Sample Input 1 :
0
Sample Output 1 :
1
-------------------------------------------------------------------


-------------------------------------------------------------------
Sample Input 2 :
00010204
Sample Output 2 :
2
-------------------------------------------------------------------


-------------------------------------------------------------------
Sample Input 3 :
708000
Sample Output 3 :
4
-------------------------------------------------------------------
*/


#include <iostream>
#include "solution.h"
using namespace std;


int countZeros(int n) {

    if (n == 0) {
        return 1;
    }
    if (n < 10) {
        return 0;
    }
    int lastDigit = n % 10;
    if (lastDigit == 0) {
        return 1 + countZeros(n / 10);
    } 
    else {
        return countZeros(n / 10);
    }

}


int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}

