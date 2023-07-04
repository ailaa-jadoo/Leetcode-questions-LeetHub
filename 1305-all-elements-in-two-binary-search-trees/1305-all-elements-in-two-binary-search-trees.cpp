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
    void inorder(TreeNode* root, vector<int>& res){
        if(root!=NULL){
            inorder(root->left, res);
            res.push_back(root->val);
            inorder(root->right, res);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res1, res2;
        inorder(root1, res1); inorder(root2, res2);
        
        for(int i=0;i<res2.size();i++)
            res1.push_back(res2[i]);
        
        sort(res1.begin(), res1.end());
        
        return res1;
    }
};