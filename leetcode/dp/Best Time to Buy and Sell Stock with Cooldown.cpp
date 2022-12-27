// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Example 1:

// Input: prices = [1,2,3,0,2]
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]
// Example 2:

// Input: prices = [1]
// Output: 0

// Constraints:

// 1 <= prices.length <= 5000
// 0 <= prices[i] <= 1000

class Solution
{
    vector<int> mem;

private:
    int profit(vector<int> &prices, int n, int curr)
    {
        if (curr >= n)
            return 0; // if the current day becomes equal or greater to the last index of prices
        if (mem[curr] != -1)
        {
            return mem[curr];
        }
        int maxval = 0;
        for (int i = curr + 1; i < n; i++)
        { // if we buy a stock on curr day and are trying to sell it near future
            if (prices[curr] < prices[i])
            { // if the price of the stock on ith day is greater than that of curr day price

                // We can try to sell on ith day
                // We have 2 choices
                // 1.We can sell the stock at ith day and findMax from (i+2)th day
                // 2.We don't sell the stock on ith day
                maxval = max(maxval, prices[i] - prices[curr] + profit(prices, n, i + 2));
            }
        }
        maxval = max(maxval, profit(prices, n, curr + 1)); // if we did not bought the stock on current day and instead went to next day to buy the stock
        mem[curr] = maxval;
        return maxval;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        mem.resize(n + 1, -1);
        return profit(prices, n, 0);
    }
};