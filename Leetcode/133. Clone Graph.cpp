/*
// Definition for a Node.
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
*/

class Solution {
    Node* dfs(Node* node,unordered_map<int,Node*>& graph)
    {
        if(graph.count(node->val))
            return graph[node->val];

        Node* temp = new Node(node->val);
        graph[node->val] = temp;
        for(auto i: node->neighbors)
        {
            temp->neighbors.push_back(dfs(i,graph));
        }
        return temp;
    }


public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;

        unordered_map<int,Node*> graph;

        return dfs(node,graph);
    }
};