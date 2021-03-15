// 148. Sort List (Medium)

#include <iostream>
#include "tree.h"
using namespace std;

/*
    Input: head = [4,2,1,3]
    Output: [1,2,3,4]

    requirement: O(nlogn) in time complexity
                 O(1) in space complexity
*/

class Solution {
public:
	ListNode* merge(ListNode* a, ListNode* b){
		ListNode* header = new ListNode(0);
		ListNode* tmp = header;

		while (a && b){
			if (a->val < b->val){
				tmp->next = a;
				a = a->next;	
			}
			else {
				tmp->next = b;
				b = b->next;
			}
			tmp = tmp->next;
		}

		if (a)
			tmp->next = a;
		if (b)
			tmp->next = b;
		return header->next;
	}

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* slow = head, *fast = head, *pre = head;
        while (fast && fast->next){
			pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

		pre->next = NULL;
		return merge(sortList(head), sortList(slow));
    }
};