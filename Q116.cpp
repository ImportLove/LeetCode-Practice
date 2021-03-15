// 116. Populating Next Right Pointers in Each Node (Medium)


#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:

	void partial_conn(Node* root){
		if (root == NULL)
			return;
		if (root->left)
			root->left->next = root->right;
		partial_conn(root->left);
		partial_conn(root->right);
	}

	void full_conn(Node* root){
		if (root == NULL)
			return;
		full_conn(root->left);
		if (root->right != NULL && root->next != NULL && root->right->next == NULL){
			root->right->next = root->next->left;
		}
		full_conn(root->right);
	}

    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;
		partial_conn(root);
        full_conn(root);
		return root;
    }
};