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
    void find(unordered_map<int,pair<int,int>>&m,TreeNode*root,int depth,int parent){
        if(!root)return;
        m[root->val]={depth,parent};
        find(m,root->left,depth+1,root->val);
        find(m,root->right,depth+1,root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int,pair<int,int>>m;
        find(m,root,0,-1);
        return m[x].second==m[y].second?false:m[x].first==m[y].first;
    }
};