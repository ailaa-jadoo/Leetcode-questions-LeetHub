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
    
    TreeNode* swapingNodes(TreeNode* root){
        if(!root)
            return NULL;
        
        swap(root->left, root->right);
        swapingNodes(root->left);
        swapingNodes(root->right);
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        return swapingNodes(root);
    }
};