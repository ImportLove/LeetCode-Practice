// 160. Intersection of Two Linked Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tmpA = headA;
        ListNode* tmpB = headB;
        ListNode* res = NULL;

        while (tmpA){
            tmpA->val *= -1;
            tmpA = tmpA->next;
        }

        while(tmpB){
            if (tmpB->val < 0){
                res = tmpB;
                break;
            }
            tmpB = tmpB->next;
        }

        tmpA = headA;
        while (tmpA){
            tmpA->val *= -1;
            tmpA = tmpA->next;
        }

        return res;
    }
};
