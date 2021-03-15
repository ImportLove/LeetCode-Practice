// 114. Flatten Binary Tree to Linked List (Medium)

#include <iostream>
#include <queue>
#include "tree.h"
using namespace std;

class Solution {
public:

    void printTreebyLevel(TreeNode* root){
        if (root == NULL)
            return;
        queue<TreeNode*> tree;
        tree.push(root);
        while (!tree.empty()){
            int size = tree.size();
            for (int i = 0; i < size; ++i){
                TreeNode* temp = tree.front();
                cout << temp->val << ' ';
                tree.pop();
                if (temp->left)
                    tree.push(temp->left);
                if (temp->right)
                    tree.push(temp->right);
            }
            cout << endl;
        }
    }

    void merge(TreeNode* root){
        // merge the left and right branches of the tree
        if (root == NULL)
            return;
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode* p = root;
        while (p->right){
            p = p->right;
        }
        p->right = tmp;
    }

    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        flatten(root->left);
        flatten(root->right);
        merge(root);
    }
};


int main(){
    Solution sol;
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(6);
    TreeNode* node4 = new TreeNode(2, node1, node2);
    TreeNode* node5 = new TreeNode(5, NULL, node3);
    TreeNode* root = new TreeNode(1, node4, node5);

    cout << "before flattern" << endl;
    sol.printTreebyLevel(root);

    sol.flatten(root);

    cout << "after flattern" << endl;
    sol.printTreebyLevel(root);


    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete root;
}