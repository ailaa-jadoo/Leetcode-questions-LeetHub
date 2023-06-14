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
    void inOrder(TreeNode* node, vector<int> &v){
        if(!node)
            return;
        inOrder(node->left, v);
        v.push_back(node->val);
        inOrder(node->right, v);        
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        
        inOrder(root, v);
        
        int minDiff=INT_MAX;
        
        for(int i=0;i<v.size()-1;i++)
            minDiff = min(minDiff, v[i+1]-v[i]);
        
        return minDiff;
    }
};