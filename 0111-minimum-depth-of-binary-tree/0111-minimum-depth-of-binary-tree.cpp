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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        int minLeftHt = minDepth(root->left);
        int minRightHt = minDepth(root->right);
        
        if(minLeftHt==0 or minRightHt==0)
            return max(minRightHt, minLeftHt)+1;
        
        return min(minRightHt, minLeftHt)+1;
    }
};