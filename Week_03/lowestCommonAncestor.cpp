/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int, TreeNode*> allFather;
    map<int, bool> vis;
    void helper(TreeNode* root){
        if (root->left != nullptr) {
            allFather[root->left->val] = root;
            helper(root->left);
        }
        if (root->right != nullptr) {
            allFather[root->right->val] = root;
            helper(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        allFather[root->val] = nullptr;
        helper(root);

        while (p != nullptr) {
            vis[p->val] = true;
            p = allFather[p->val];
        }
        while (q != nullptr) {
            if (vis[q->val]) return q;
            q = allFather[q->val];
        }
        return nullptr;
    }
};