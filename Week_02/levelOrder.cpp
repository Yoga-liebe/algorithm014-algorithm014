/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};x
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root)return res;
        queue<Node*> queueNode;
        queueNode.push(root);
        while(!queueNode.empty()){
            vector<int> level;
            int size = queueNode.size();
            for(int i = 0;i < size;i++){
                Node* nodeTmp = queueNode.front();
                queueNode.pop();
                level.push_back(nodeTmp->val);
                for(int j = 0;j < nodeTmp->children.size();j++){
                    queueNode.push(nodeTmp->children[j]);
                } 
            }
            res.push_back(level);
        }
        return res;
    }
};