// 109. Convert Sorted List to Binary Search Tree (Medium)

#include <iostream>
#include "tree.h"
using namespace std;

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL )
            return NULL;

        if (head->next == NULL){
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
            
        ListNode* fast = head, *slow = head, *pre = head;

        while (fast && fast->next){
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        pre->next = NULL;

        TreeNode* root = new TreeNode(slow->val, 
            sortedListToBST(head), sortedListToBST(slow->next));
        
        return root;
    }
};