/*
FIRST NON-REPEATING CHARACTER

Problem statement
Ninja is now bored with numbers and is now playing with characters but hates when he gets repeated characters. 
Ninja is provided a string, and he wants to return the first unique character in the string.The string will 
contain characters only from the English alphabet set, i.e., ('A' - 'Z') and ('a' - 'z'). If there is no 
non-repeating character, print the first character of the string. If there is no non-repeating character, return
the first character of the string.


Constraints:
1 <= T <= 10
1 <= Length of Input String <= 10^4

Time Limit: 1 sec 


-------------------------------------------------------------------------------------------------------------------
Sample Input 1 :
2
aDcadhc
AabBcC
Sample Output 1:
 D
 A
Explanation for Sample Input 1:
In the first test case, ‘a’ is repeated.’ D’ is the first non-repeating character in the string, so we return it.

In the second test case, all the characters are non-repeating, so we return the first character.
-------------------------------------------------------------------------------------------------------------------


-------------------------------------------------------------------------------------------------------------------
Sample Input 2 :
 2
 ABcd
 AAAbcdb
Sample Output 2:
 A
 c
-------------------------------------------------------------------------------------------------------------------
*/


#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#include <bits/stdc++.h> 
char firstNonRepeatingCharacter(string str) {
  unordered_map<char, int> frequency;
    unordered_map<char, int> firstOccurrence;

    // Record the frequency of each character and their first occurrence index
    for (int i = 0; i < str.length(); ++i) {
        frequency[str[i]]++;
        if (firstOccurrence.find(str[i]) == firstOccurrence.end()) {
            firstOccurrence[str[i]] = i;
        }
    }

    // Find the first non-repeating character
    int minIndex = str.length();
    char result = str[0];
    for (auto it : frequency) {
        if (it.second == 1) {
            int index = firstOccurrence[it.first];
            if (index < minIndex) {
                minIndex = index;
                result = str[index];
            }
        }
    }

    return result;
}


class Runner
{
    int t;
    
    vector<string> arr;

public:
    void takeInput()
    {

 cin >> t;
        arr.resize(t);
        
        for (int tc = 0; tc < t; tc++)
        {
       cin>>arr[tc];

        }

    }

    void execute()
    {
         vector<string> arrCopy = arr;
        for (int i=0;i<t;i++){
            firstNonRepeatingCharacter(arrCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int tt=0;tt<t;tt++){
            char v=firstNonRepeatingCharacter(arr[tt]);
            {
              cout<<v;         
            }
            cout<<"\n";
        }
    }
};

int main()
{

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}
