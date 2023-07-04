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
    vector<int> res1, res2;
    void inorder_1(TreeNode* root){
        if(root!=NULL){
            inorder_1(root->left);
            res1.push_back(root->val);
            inorder_1(root->right);
        }
    }
    void inorder_2(TreeNode* root){
        if(root!=NULL){
            inorder_2(root->left);
            res2.push_back(root->val);
            inorder_2(root->right);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder_1(root1);
        inorder_2(root2);
        
        for(int i=0;i<res2.size();i++)
            res1.push_back(res2[i]);
        
        sort(res1.begin(), res1.end());
        
        return res1;
    }
};