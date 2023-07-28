class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> t(n, vector<int>(n, 0));
        
        for(int i=0;i<n;i++)
            t[i][i] = nums[i];
        
        for(int diff = 1;diff<n;diff++)
        {
            for(int left = 0;left<n-diff;left++){
                int right = left + diff;
                t[left][right] = max(nums[left]-t[left+1][right], nums[right]-t[left][right-1]);
            }                
        }
        
        return t[0][n-1] >=0;
    }
};