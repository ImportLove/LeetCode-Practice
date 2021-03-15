// 147. Insertion Sort List (Medium)

#include <iostream>
#include "tree.h"
using namespace std;

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* unsorted = head->next;
        ListNode* pre_unsorted = head;
        while (unsorted != NULL){
            int value = unsorted->val;
            if (value >= pre_unsorted->val){
                unsorted = unsorted->next;
                pre_unsorted = pre_unsorted->next;
                continue;
            }
            if (value < head->val){
                ListNode* cp = unsorted->next;
                unsorted->next = head;
                head = unsorted;
                unsorted = cp;
                pre_unsorted->next = unsorted;
            }
            else {
                ListNode* tmp = head->next;
                ListNode* pre_tmp = head;
                while (pre_tmp != unsorted){
                    if (value >= pre_tmp->val && value <= tmp->val){
                        ListNode* cp = unsorted->next;
                        pre_tmp->next = unsorted;
                        unsorted->next = tmp;
                        unsorted = cp;
                        pre_unsorted->next = unsorted;
                        break;
                    }
                    pre_tmp = pre_tmp->next;
                    tmp = tmp->next;
                }
            }
            
        }
        return head;
    }
};