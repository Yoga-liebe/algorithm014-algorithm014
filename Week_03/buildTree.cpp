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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd){
        if(preStart > preEnd){
            return nullptr;
        }
        int rootPos = 0; // middle用来定位root在inorder中的位置
        for(auto i : inorder)
        {
            if(i != preorder[preStart]) rootPos ++;
            else break;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        root->left = helper(preorder,inorder,preStart + 1,preStart + rootPos - inStart
        ,inStart, rootPos - 1);

        root->right = helper(preorder,inorder,preEnd - (inEnd - rootPos) + 1,preEnd,
        rootPos + 1,inEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || preorder.size() != inorder.size()){
            return nullptr;
        }
        return helper(preorder,inorder,0,preorder.size() - 1,0,inorder.size() - 1);
    }
};