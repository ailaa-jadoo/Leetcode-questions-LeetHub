class Solution {
public:
    bool subsetSum(vector<int> &nums, int sum){
        
        vector<vector<bool>> t(nums.size() + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= nums.size(); i++) 
            t[i][0] = true;
        
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<sum+1;j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        return t[nums.size()-1][sum];
    }
    
    bool canPartition(vector<int>& nums) {       
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2!=0)
            return false;
        
        return subsetSum(nums, sum/2);
    }
};