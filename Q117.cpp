// 117. Populating Next Right Pointers in Each Node II (Medium)

#include <iostream>
#include <queue>
#include "tree.h"
using namespace std;

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            int size = q.size();
            Node* pre = q.front();
            q.pop();

            if (pre->left)
                q.push(pre->left);
            if (pre->right)
                q.push(pre->right);
            for (int i = 1; i < size; ++i){
                Node* tmp = q.front();
                q.pop();

                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
                pre->next = tmp;
                pre = tmp;
            }
        }
        return root;
    }
};
