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
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int maxSum = INT_MIN;
        int res =0, level=0;
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            level++;
            int levelSize = q.size();
            int levelSum = 0;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // Update the sum at the current level
                levelSum += curr->val;

                // Enqueue the left and right children of the current node
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }

            // Update the maximum sum
            if(levelSum>maxSum){
                maxSum = levelSum;
                res = level;
            }
        }

        return res;
    }
};