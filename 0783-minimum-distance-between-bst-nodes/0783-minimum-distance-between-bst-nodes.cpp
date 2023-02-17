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
    void inorder(TreeNode* root, vector<int> &res){
        if(root){
            inorder(root->left, res);
            res.push_back(root->val);
            inorder(root->right, res);
        }
    }
    
    int minDiffInBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        int diff=abs(res[0]-res[1]);
        for(int i=0;i<res.size();i++)
            for(int j=i+1;j<res.size();j++){
                diff = min(diff, abs(res[i]-res[j]));
            }
        
        return diff;
    }    
};