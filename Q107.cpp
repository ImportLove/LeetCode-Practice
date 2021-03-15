// 107. Binary Tree Level Order Traversal II (Easy)

#include <iostream>
#include <vector>
#include <queue>
#include "tree.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int size = q.size();
            vector<int> temp;
            for(int i = 0; i < size; ++i){
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }

            ans.push_back(temp);
        }

        for(size_t i = 0; i < ans.size()/2; ++i)
            swap(ans[i], ans[ans.size()-i-1]);
        return ans;
    }
};