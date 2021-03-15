// 103. Binary Tree Zigzag Level Order Traversal (Medium)

#include <iostream>
#include <vector>
#include <queue>
#include "tree.h"
using namespace std;

class Solution {
public:
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        bool normal_order = true;
        vector<vector<int>> result;
        if (root == NULL)
            return result;
        queue<TreeNode*> tree;
        tree.push(root);

        while (!tree.empty()){
            int size = tree.size();
            vector<int> tmp(size, 0);

            for (int i = 0; i < size; ++i){
                TreeNode* p = tree.front();
                tree.pop();
                if (normal_order)
					tmp[i] = p->val;
				else
					tmp[size-i-1] = p->val;

                
                if (p->left)
                    tree.push(p->left);
                if (p->right)
                    tree.push(p->right);
            }
            result.push_back(tmp);
            normal_order = !normal_order;
        }

        return result;
    }
};