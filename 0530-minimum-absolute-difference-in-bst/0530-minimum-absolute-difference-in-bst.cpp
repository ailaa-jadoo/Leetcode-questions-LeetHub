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
    TreeNode* prevNode;
    int minDiff = INT_MAX;
    
    void inOrder(TreeNode* node){
        if(!node)
            return;
        
        inOrder(node->left);
        
        if(prevNode!=NULL)
            minDiff = min(minDiff, node->val-prevNode->val);
        prevNode = node;
        
        inOrder(node->right);        
    }
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        
        return minDiff;
    }
};              