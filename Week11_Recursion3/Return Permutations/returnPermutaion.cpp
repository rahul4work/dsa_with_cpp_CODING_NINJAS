/*
RETURN PERMUTAION - String
level: hard
  
Problem statement
Given a string S, find and return all the possible permutations of the input string.

Note 1 : The order of permutations is not important. Note 2 : If original string contains
duplicate characters, permutations will also be duplicates.



-----------------------------------------------------------------------------------------
Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba
-----------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>

#include <string>
#include <vector>
using namespace std;

void permute(string input, int l, int r, vector<string> &result) {
    if (l == r) {
        result.push_back(input);
    } else {
        for (int i = l; i <= r; i++) {
            swap(input[l], input[i]);
            permute(input, l + 1, r, result);
            swap(input[l], input[i]); // backtrack
        }
    }
}

int returnPermutations(string input, string output[]){
	vector<string> result;
    permute(input, 0, input.size() - 1, result);
    for (int i = 0; i < result.size(); i++) {
        output[i] = result[i];
    }
    return result.size();
}

  
using namespace std;

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}


