// 123. Best Time to Buy and Sell Stock III (Hard)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        
        int size = prices.size();
        int min_price = prices[0];
        vector<int> maxp(size, 0);
        maxp[0] = 0;
        for (int i = 1; i < size; ++i){
            min_price = min(min_price, prices[i]);
            maxp[i] = max(prices[i]-min_price, maxp[i-1]);
        }

        int profit = 0;
        int max_price = prices[size-1];
        for (int i = size-2; i >= 0; --i){
            max_price = max(max_price, prices[i]);
            profit = max(profit, maxp[i] + max_price-prices[i]);
        }

        return profit;
    }
};