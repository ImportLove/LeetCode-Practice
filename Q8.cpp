// 8. String to Integer (atoi)

#include <iostream>
#include <ctype.h>
using namespace std;

class Solution {
public:

    int myAtoi(string str) {
        if (str.size() == 0)
			return 0;
		
		int sign = 1;
		size_t index = 0;

		for (; index < str.size(); ++index){
			if (str.at(index) != ' ')
				break;
		}

		if (index == str.size())
			return 0;

		// read sign
		if (str.at(index) == '-'){
			sign = -1;
			++index;
		}
			
		else if (str.at(index) == '+'){
			sign = 1;
			++index;
		}
		
		long sum = 0;
		
		// read digit
		for (; index < str.size(); ++index){
			char cur = str.at(index);

			if ( !isdigit(cur) )
				break;
			sum = sum*10 + (cur-'0');
			if (sum*sign >= INT32_MAX)
				return INT32_MAX;
			if (sum*sign <= INT32_MIN)
				return INT32_MIN;
		}

		return sum*sign;
		
    }
};

int main(){
	Solution sol;
	cout << sol.myAtoi("20000000000000000000") << endl;
	return 0;
}