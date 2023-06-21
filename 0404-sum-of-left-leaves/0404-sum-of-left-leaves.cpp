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
    void calcSum(TreeNode* node, bool isLeft){
        if(isLeft and node->left==NULL and node->right==NULL){
            sum+=node->val;
            return;
        }
        if(node->left!=NULL)
            calcSum(node->left, true);
        if(node->right!=NULL)
            calcSum(node->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return NULL;
        calcSum(root, false);
        return sum;
    }
};