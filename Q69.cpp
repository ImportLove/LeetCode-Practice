// 69. Sqrt(x) (Easy)

#include <iostream>
using namespace std;

class Solution {
public:

	int binary_search_ans(int x, int begin, int end){
		if (begin == end)
			return begin;
		long mid = (end - begin) / 2 + begin;
		if (mid*mid < x && (mid+1)*(mid+1) > x)
			return mid;
		else if (mid*mid < x)
			return binary_search_ans(x, mid + 1, end);
		else 
			return binary_search_ans(x, begin, mid);
	}

    int mySqrt(int x) {
        if (x == 0 || x == 1)
			return x;

		return binary_search_ans(x, 0, x/2);
    }
};