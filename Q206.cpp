// 206. Reverse Linked List

#include <iostream>
#include "tree.h"
using namespace std;

class Solution {
public:

    /*
    ListNode* copyList(ListNode* head){
        ListNode* new_head = new ListNode(head->val);
        ListNode* tmp = new_head;
        while (head->next){
            tmp->next = new ListNode(head->next->val);
            head = head->next;
            tmp = tmp->next;
        }
        return new_head;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head)
            return NULL;
        ListNode* new_head = copyList(head);
        ListNode* p1 = new_head, *p2 = new_head->next;
        new_head->next = NULL;

        while (p2){
            ListNode* tmp = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = tmp;
        }
        return p1;
    }
    */

    // recursive version

    ListNode* helper(ListNode* pre, ListNode* cur, ListNode* post){
        cur->next = pre;
        if (!post)
            return cur;
        return helper(cur, post, post->next);
    }

    ListNode* reverseList(ListNode* head){
        if (!head || !head->next)
            return head;
        return helper(NULL, head, head->next);
    }
};
