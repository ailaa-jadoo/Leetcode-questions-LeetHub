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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
    
        vector<int> nodes;
    
        nodes.push_back(root->val);
    
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
        
            if(curr->left){
                nodes.push_back(curr->left->val);
                q.push(curr->left);
            }else
                nodes.push_back(-1);
        
            if(curr->right){
                nodes.push_back(curr->right->val);
                q.push(curr->right);
            }else
                nodes.push_back(-1);
        }
    
        int n=nodes.size();
    
        int maxele=-1;
        for(int i=n-1;i>=0;i--){
            if(nodes[i]>maxele)
                maxele=nodes[i];
        
            if(maxele>0 && nodes[i]==-1)
                return false;
        }
    
        return true;
    
    }
};