/*
MERGE K SORTED ARRAYS

Problem statement
Given k no. of different size arrays, which are sorted individually (in ascending order). 
You need to merge all the given arrays such that output array should be sorted (in ascending order).

Hint : Use Heaps.

Constraints:
0 <= k <= 1000
0 <= n1, n2 <= 10000
Time Limit: 1 second


----------------------------------------------------------------------------------------------------
Sample Input 1:
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 1:
0 1 2 5 6 9 45 78 90 100 234
----------------------------------------------------------------------------------------------------
*/




#include <iostream>
#include <vector>
using namespace std;

#include <queue>

struct HeapNode {
    int element;
    int index; 
    int arrayIndex; 
};

struct Compare {
    bool operator()(const HeapNode& a, const HeapNode& b) const {
        return a.element > b.element; 
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>*>& input) {

    priority_queue<HeapNode, vector<HeapNode>, Compare> minHeap;


    for (int i = 0; i < input.size(); i++) {
        if (!input[i]->empty()) {
            minHeap.push({ (*input[i])[0], 0, i }); 
        }
    }

    vector<int> merged; 

    while (!minHeap.empty()) {

        HeapNode root = minHeap.top();
        minHeap.pop();

        merged.push_back(root.element);

        int nextIndex = root.index + 1;
        if (nextIndex < input[root.arrayIndex]->size()) {
            minHeap.push({ (*input[root.arrayIndex])[nextIndex], nextIndex, root.arrayIndex });
        }
    }

    for (auto vec : input) {
        delete vec;
    }

    return merged;
}

int main() {
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}



