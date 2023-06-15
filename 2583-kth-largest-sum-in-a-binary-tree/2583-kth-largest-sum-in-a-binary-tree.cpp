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
    vector<long long> DFSLevelSums(TreeNode* root){
        vector<long long> levelSum;
        
        if(!root)
            return levelSum;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            long long currlevelSum = 0;
            int levelSize = q.size();
            
            for(int i=0;i<levelSize;i++){
                TreeNode* curr = q.front();
                q.pop();
                
                currlevelSum += curr->val;
                
                if(curr->left != nullptr)
                    q.push(curr->left);
                if(curr->right != nullptr)
                    q.push(curr->right);
            }
            levelSum.push_back(currlevelSum);
        }
        
        return levelSum;
    }
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sums = DFSLevelSums(root);
        
        if(sums.size()<k)
            return -1;
        
        sort(sums.begin(), sums.end());
        reverse(sums.begin(), sums.end());
        
        return sums[k-1];
    }
};