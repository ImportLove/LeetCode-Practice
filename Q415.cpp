// 415. Add Strings

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    /*
    string addStrings(string num1, string num2) {

        int size1 = int(num1.size());
        int size2 = int(num2.size());
        int carry = 0, index = 0;
        string ans = "";
        for (; index < min(size1, size2); ++index){
            int res = (num1.at(size1-index-1)-'0') +
                (num2.at(size2-index-1)-'0') + carry;
            if (res >= 10){
                res -= 10;
                carry = 1;
            }
            else
                carry = 0;
            ans = string(1, res+'0') + ans;
        }

        for (; index < size1; ++index){
            int res = (num1.at(size1-index-1) - '0') + carry;
            if (res >= 10){
                res -= 10;
                carry = 1;
            }
            else
                carry = 0;
            ans = string(1, res+'0') + ans;
        }

        for (; index < size2; ++index){
            int res = (num2.at(size2-index-1) - '0') + carry;
            if (res >= 10){
                res -= 10;
                carry = 1;
            }
            else
                carry = 0;
            ans = string(1, res+'0') + ans;
        }

        if (carry == 1)
            ans = "1" + ans;

        return ans;
    }
    */

    // alternative method
    string addStrings(string num1, string num2){

        int count1 = int(num1.size()-1);
        int count2 = int(num2.size()-1);
        int carry = 0;
        string ans = "";

        while (count1 >= 0 || count2 >= 0 || carry > 0){
            if (count1 >= 0){
                carry += (num1.at(count1)-'0');
                --count1;
            }

            if (count2 >= 0){
                carry += (num2.at(count2)-'0');
                --count2;
            }

            ans += ((carry%10)+'0');
            carry /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
