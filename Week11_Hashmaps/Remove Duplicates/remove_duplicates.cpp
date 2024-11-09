/*
REMOVE DUPLICATES

Problem statement
Ninja is playing with numbers but hates when he gets duplicate numbers. Ninja is provided 
an array, and he wants to remove all duplicate elements and return the array, but he has 
to maintain the order in which the elements were supplied to him.


Constraints:
1 <= T <= 10
1 <= N <= 5*10^3
-10^5 <= arr[i] <= 10^5

Time Limit: 1 sec


---------------------------------------------------------------------------------------------
Sample Input 1 :
2
5
1 2 2 3 4
5
10 11 23 23 23 
Sample Output 1:
 1 2 3 4
 10 11 23
Explanation for Sample Input 1:
In the first test case, ‘2’ is a duplicate element, and there are two occurrences of ‘2’,
so one ‘2’ is removed, and the resultant array becomes [1 2 3 4].

In the second test case, ‘23’ is a duplicate element, and there are three occurrences of 
‘23’, so two occurrences of ‘23’ must be removed, and the resultant array becomes [10 11 23].
---------------------------------------------------------------------------------------------



---------------------------------------------------------------------------------------------
Sample Input 2 :
 2
 10
 1 3 3 3 3 3 4 9 23 35
 5
 10 10 10 10 10 
Sample Output 2:
 1 3 4 9 23 35
 10 
---------------------------------------------------------------------------------------------
*/


#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#include <bits/stdc++.h> 
vector<int> removeDuplicates(vector<int> arr) {
  unordered_set<int> seen;
    vector<int> result;
    for (int num : arr) {
        if (seen.find(num) == seen.end()) {
            seen.insert(num);
            result.push_back(num);
        }
    }
    return result;
}

class Runner
{
    int t;

    vector<vector<int> > arr;

public:
    void takeInput()
    {

 cin >> t;
        arr.resize(t);
        

        for (int tc = 0; tc < t; tc++)
        {
            int n;
            cin >> n;



            arr[tc].resize(n);

            for (int i = 0; i < n; i++)
            {
                cin >> arr[tc][i];
            }
        }   
    }

    void execute()
    {
         vector<vector<int> > arrCopy = arr;
        for (int i=0;i<t;i++){
            removeDuplicates(arrCopy[i]);
        }
    }


    void executeAndPrintOutput()
    {
        for (int tt=0;tt<t;tt++){
            vector<int> v=removeDuplicates(arr[tt]);
            for (int i=0; i < v.size(); i++){
              cout<<v[i]<<" ";         
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


