// 122. Best Time to Buy and Sell Stock II (Easy)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxp = 0;
        for (int i = 1; i < int(prices.size()); ++i){

            if (prices[i] > prices[i-1]){
                maxp += (prices[i]-prices[i-1]);
            }
        }

        return maxp;
    }
};