// 4. Median of Two Sorted Arrays

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int size1 = int(nums1.size());
        int size2 = int(nums2.size());

        if (size1 > size2)
            return findMedianSortedArrays(nums2, nums1);

        int begin = 0, end = size1;

        while (begin <= end){
            int mid1 = (begin+end)/2;
            int mid2 = (size1+size2)/2-mid1;

            int left1 = (mid1 == 0) ? INT32_MIN : nums1[mid1-1];
            int right1 = (mid1 == size1) ? INT32_MAX : nums1[mid1];
            int left2 = (mid2 == 0) ? INT32_MIN : nums2[mid2-1];
            int right2 = (mid2 == size2) ? INT32_MAX : nums2[mid2];

            if (left1 <= right2 && left2 <= right1){
                if ((size1+size2)%2 == 0)
                    return double(max(left1, left2) + min(right1, right2))/2;
                else
                    return min(right1, right2);
            }

            else if (left1 > right2)
                end = mid1 - 1;
            else
                begin = mid1 + 1;
        }

        return -1;
    }
};
