class Solution {
public:
    void backtracking(vector<vector<int>> &res, vector<int>& temp, vector<int>& nums, int remain, int start){
        if(remain<0)
            return;
        else if(remain == 0)
            res.push_back(temp);
        else{
            for(int i=start;i<nums.size();i++){
                temp.push_back(nums[i]);
                backtracking(res, temp, nums, remain-nums[i], i);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        
        backtracking(res, temp, nums, target, 0);
        
        return res;
    }
};