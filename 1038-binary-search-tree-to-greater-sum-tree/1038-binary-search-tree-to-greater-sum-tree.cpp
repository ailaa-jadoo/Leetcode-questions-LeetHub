/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum=0;
    TreeNode* bstToGst(TreeNode* root) {
        if(!root)
            return 0;
        
        bstToGst(root->right);
        int currNodeVal = root->val;
        root->val = sum+currNodeVal;
        sum=sum+currNodeVal;
        bstToGst(root->left);
        
        return root;
    }
};