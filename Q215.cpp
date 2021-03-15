// 215. Kth Largest Element in an Array (Medium)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
	Note:
		Solution 1 uses priority and Solution 2 uses patial quick sort
		Solution 1 runs much faster than Solution 2 and I don't know why
		However, the fast way to do this problem is to sort the vector 
		directly.

		Delete the number after Solution (e.g. Solution1 -> Solution) if 
		you want to submit the answer to leetcode for testing
*/


class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {

		if (nums.size() == 0)
			return 0;
        priority_queue<int> pq;
		for (size_t i = 0; i < nums.size();++i)
			pq.push(nums[i]);
		
		for (int i = 0; i < k-1; ++i)
			pq.pop();
		
		return pq.top();
    }
};


class Solution2 {
public:

	int pivot(vector<int>& nums, int begin, int end){

		int small = begin-1;
		for (int i = begin; i <= end-1; ++i){
			if (nums[i] < nums[end]){
				++small;
				swap(nums[i],nums[small]);
			}
		}
		++small;
		swap(nums[small], nums[end]);
		return small;
	}

	void findKthLargest(vector<int>& nums, int k, int begin, int end){

		if (begin >= end)
			return;

		int index = pivot(nums, begin, end);

		if (index == nums.size()-k)
			return;
		else if (index > nums.size()-k)
			findKthLargest(nums, k, begin, index-1);
		else 
			findKthLargest(nums, k, index+1, end);
	}

    int findKthLargest(vector<int>& nums, int k) {
		if (nums.size() == 0)
			return 0;
		findKthLargest(nums, k, 0, nums.size()-1);
		return nums[nums.size()-k];
		
    }
};

