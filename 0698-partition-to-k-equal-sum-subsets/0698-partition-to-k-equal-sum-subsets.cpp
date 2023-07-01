class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
            return false;
        
        int targetSum = sum / k;
        int n = nums.size();
        vector<bool> dp(1 << n, false);
        vector<int> subsetSum(1 << n, 0);
        
        dp[0] = true; // Empty subset can be formed with sum 0
        
        for (int mask = 0; mask < (1 << n); mask++) {
            if (!dp[mask])
                continue;
            
            for (int i = 0; i < n; i++) {
                int nextMask = mask | (1 << i);
                if (mask != nextMask && !dp[nextMask]) {
                    if (nums[i] <= targetSum - (subsetSum[mask] % targetSum)) {
                        dp[nextMask] = true;
                        subsetSum[nextMask] = subsetSum[mask] + nums[i];
                    } else {
                        break; // Early pruning if the current number doesn't fit in the current subset
                    }
                }
            }
        }
        
        return dp[(1 << n) - 1];
    }
};
