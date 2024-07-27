/*
STOCK SPAN

Problem statement
Amit has been working with an organization called 'Money Traders' for the past few years. The organization
is into the money trading business. His manager assigned him a task. For a given array/list of stock's 
prices for N days, find the stock's span for each day.

The span of the stock's price today is defined as the maximum number of consecutive days(starting from 
today and going backwards) for which the price of the stock was less than today's price.

For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], then the 
stock spans will be [1, 1, 1, 2, 1, 4, 6].

Explanation:
On the sixth day when the price of the stock was 75, the span came out to be 4, because the last 4 prices
(including the current price of 75) were less than the current or the sixth day's price.

Similarly, we can deduce the remaining results.
Amit has to return an array/list of spans corresponding to each day's stock's price. Help him to achieve 
the task.


Constraints:
0 <= N <= 10^7
1 <= X <= 10^9
Where X denotes the stock's price for a day.

Time Limit: 1 second



-----------------------------------------------------------------------------------------------------------
Sample Input 1:
4
10 10 10 10
Sample Output 1:
1 1 1 1 
-----------------------------------------------------------------------------------------------------------



-----------------------------------------------------------------------------------------------------------
Sample Input 2:
8
60 70 80 100 90 75 80 120
Sample Output 2:
1 2 3 4 1 1 2 8 
-----------------------------------------------------------------------------------------------------------
*/



#include <iostream>
#include <stack>
using namespace std;

void calculateSpan(int prices[], int n, int spans[]) {
    //Write your code here
     stack<int> s;

    // Initialize the span of the first day to 1
    spans[0] = 1;
    s.push(0);

    // Calculate span for the rest of the days
    for (int i = 1; i < n; i++) {
        // Pop elements from the stack while the stack is not empty and
        // the price at the top of the stack is less than the current price
        while (!s.empty() && prices[s.top()] < prices[i]) {
            s.pop();
        }

        // If the stack is empty, it means the current price is the highest
        // seen so far, so the span is the entire range from the beginning to
        // the current day (i + 1)
        if (s.empty()) {
            spans[i] = i + 1;
        } else {
            // Otherwise, the span is the difference between the current day
            // and the day at the top of the stack
            spans[i] = i - s.top();
        }

        // Push the current index onto the stack
        s.push(i);
    }
}

int main() {
    int n;
    cin >> n;

    int* prices = new int[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    int* spans = new int[n];
    calculateSpan(prices, n, spans);

    for (int i = 0; i < n; i++)
        cout << spans[i] << " ";

    delete[] prices;
    delete[] spans;

    return 0;
}

