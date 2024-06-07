/*
NUMBER OF DIGITS

Problem statement
You are given a number 'n'.

Return number of digits in ‘n’.

Constraints:
1 <= ‘n’ <= 10^9

Example:
Input: 'n' = 123

Output: 3

Explanation:
The 3 digits in ‘123’ are 1, 2 and 3. 

----------------------------------------
Sample Input 1:
121
Sample Output 1:
3
----------------------------------------

  
----------------------------------------
Sample Input 2:
38
Sample Output 2:
2
----------------------------------------
*/


#include <iostream>
#include <cmath>
using namespace std;

int countDigits(int n){
	if (n == 0) {
        return 1;
    }
    return floor(log10(abs(n))) + 1;
}

int main() {

    int n;
    cin>>n;

    cout<<countDigits(n) <<endl;
    

    return 0;
}
