// 102. Binary Tree Level Order Traversal (Medium)

#include <iostream>
#include <vector>
#include <queue>
#include "tree.h"
using namespace std;

class Solution {
public:
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL)
            return result;
        queue<TreeNode*> tree;
        tree.push(root);

        while (!tree.empty()){
            int size = tree.size();
            vector<int> tmp;

            for (int i = 0; i < size; ++i){
                TreeNode* p = tree.front();
                tree.pop();
                tmp.push_back(p->val);

                if (p->left)
                    tree.push(p->left);
                if (p->right)
                    tree.push(p->right);
            }
            result.push_back(tmp);
        }

        return result;
    }
};