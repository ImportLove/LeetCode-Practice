// 24. Swap Nodes in Pairs (Medium)

#include <iostream>
#include "tree.h"
using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* first = head, *second = head->next;
        head = second;
        ListNode* tmp = head;
        while (first != NULL && second != NULL){
            if (tmp != head)
                tmp->next = second;
            tmp = second->next;
            second->next = first;
            first->next = tmp;
            tmp = first;
            first = first->next;
            if (first == NULL)
                return head;
            second = first->next;
        }

        return head;
        
    }
};
