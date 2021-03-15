// 133. Clone Graph (Medium)

/*
	Further notice:
		1. Use an additional unordered_set for checking if 
			one node is in the unordered_map will improve 
			the speed since the time complexity of searching
			one specific element in unordered_set is O(1) but 
			O(lg n) in unordered_map
		2. Wait for me to update ( LOL :) )
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {

public:
    unordered_map<Node*, Node*> map;
    
    void DFS (Node* node, Node* new_graph){
        
        for (Node* item : node->neighbors){
			
            if (map.find(item) == map.end()){
				Node* tmp = new Node(item->val);
                map[item] = tmp;
                DFS(item, tmp);
            }
			
			new_graph->neighbors.push_back(map[item]);
        }
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;

        Node* new_graph = new Node(node->val);
        map[node] = new_graph;
        DFS(node, new_graph);
        return map[node];
    }
};