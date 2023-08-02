class Solution {
public:
    void backtracking(vector<vector<int>> &res, vector<int>& temp, vector<int>& nums, int remain, int start){
        if(remain<0)
            return;
        else if(remain == 0)
            res.push_back(temp);
        else{
            for(int i=start;i<nums.size();i++){
                if(i>start and nums[i]==nums[i-1])
                    continue;
                temp.push_back(nums[i]);
                backtracking(res, temp, nums, remain-nums[i], i+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        
        sort(nums.begin(), nums.end());
        backtracking(res, temp, nums, target, 0);
        
        return res;
    }
};