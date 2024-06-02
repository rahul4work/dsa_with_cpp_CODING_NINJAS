/*
COUNT PAIRS

Problem statement
You have been given a vectors of pairs. Your task is to complete the
function given which counts the pairs which have first value greater
than their second value and returns the count.

Note:
You don't have to print anything it has been already taken care of. 
Just complete the function as required and return the count.


-------------------------------------------------------------------
Sample Input 1
5
1 2
3 0
7 5
8  4
10 9
Output 1
4
-------------------------------------------------------------------
*/


#include <iostream>
#include <vector>
#include<utility>

using namespace std;

int countPairs(vector<pair<int,int>> a){

    int count = 0;
    for (const auto& p : a) {
        if (p.first > p.second) {
            count++;
        }
    }
    return count;
    
}

int main(){
    
    int n;
    cin>>n;
    
    vector<pair<int,int>> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    cout<<countPairs(a);
    return 0;
}


