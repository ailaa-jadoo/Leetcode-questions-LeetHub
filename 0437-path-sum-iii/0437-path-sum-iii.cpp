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
    int ans=0;
    void helper(TreeNode* root,long long int targetSum){
        if(root==NULL){
            return;
        }
        if(root->val==targetSum){
            ans++;
        }
        helper(root->left,targetSum-(root->val));
        helper(root->right,targetSum-(root->val));
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return ans;
        }
        helper(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return ans;
    }
};