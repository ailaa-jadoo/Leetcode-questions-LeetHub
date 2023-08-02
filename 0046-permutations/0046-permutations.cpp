class Solution {
public:
    
    void backtrack(vector<vector<int>> &res, vector<int> &temp, vector<int> &nums, vector<bool> &used){
        if(temp.size() == nums.size())
            res.push_back(temp);
        else{
            for(int i = 0;i<nums.size();i++){
                if(used[i]==true)
                    continue;
            
                used[i] = true;
                temp.push_back(nums[i]);
                backtrack(res, temp, nums, used);
                used[i] = false;
                temp.pop_back();
            }
        }
        
            
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        
        backtrack(res, temp, nums, used);
        
        return res; 
    }
};