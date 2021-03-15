// 121. Best Time to Buy and Sell Stock (Easy)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int maxp = INT32_MIN;
        int min_price = INT32_MAX;

        for (int i = 0; i < int(prices.size()); ++i){
            min_price = min(min_price, prices[i]);
            maxp = max(maxp, prices[i]-min_price);
        }

        return maxp;
    }
};