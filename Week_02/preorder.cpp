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
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root)return res;
        stack<Node*> treeStack;
        treeStack.push(root);
        while(!treeStack.empty()){
            Node* curNode = treeStack.top();
            res.push_back(curNode->val);
            treeStack.pop();
            for(int i = curNode->children.size() - 1; i >= 0;i--){
                treeStack.push(curNode->children[i]);
            }
        }
        return res;
    }
};