class Solution {
public:
    void backtrack(vector<vector<int>> &res, vector<int> &temp, vector<int> &nums, int start){
        res.push_back(temp);
        for(int i=start; i<nums.size();i++){
            if(i>start and nums[i] == nums[i-1])
                continue;
            
            temp.push_back(nums[i]);
            backtrack(res, temp, nums, i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        
        sort(nums.begin(), nums.end());
        backtrack(res, temp, nums, 0);
        
        return res;
    }
};