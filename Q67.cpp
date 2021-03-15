// 67. Add Binary (Easy)

#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        char zero = '0';
        char one = '1';
        int carry_in = 0;
        int index_a = 0, index_b = 0;
        while (index_a < a.size() && index_b < b.size()){
            int bit_a = a.at(a.size()-1-index_a)-'0';
            int bit_b = b.at(b.size()-1-index_b)-'0';
            int sum = carry_in + bit_a + bit_b;
            carry_in = 0;
            if (sum == 0)
                ans = zero + ans;
            else if (sum == 1)
                ans = one + ans;
            else if (sum == 2){
                ans = zero + ans;
                carry_in = 1;
            }
            else if (sum == 3){
                ans = one + ans;
                carry_in = 1;
            }
            ++index_a;
            ++index_b;
        }

        while (index_a < a.size()){
            int sum = carry_in + (a.at(a.size()-1-index_a)-'0');
            carry_in = 0;
            if (sum == 0)
                ans = zero + ans;
            else if (sum == 1)
                ans = one + ans;
            else if (sum == 2){
                ans = zero + ans;
                carry_in = 1;
            }
            ++index_a;
        }

        while (index_b < b.size()){
            int sum = carry_in + (b.at(b.size()-1-index_b)-'0');
            carry_in = 0;
            if (sum == 0)
                ans = zero + ans;
            else if (sum == 1)
                ans = one + ans;
            else if (sum == 2){
                ans = zero + ans;
                carry_in = 1;
            }
            ++index_b;
        }

        if (carry_in == 1)
            ans = one + ans;
        return ans;
    }
};