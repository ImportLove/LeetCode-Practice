// 142. Linked List Cycle II (Medium)

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* fast = head, *slow = head;
		int step_slow = 0;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) 
				break;
        }

        if (fast == NULL)
            return NULL;

		fast = head;
		while (fast != slow){
			fast = fast->next;
			slow = slow->next;
		}

		return slow;
    }
};