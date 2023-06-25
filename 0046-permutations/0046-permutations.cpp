class Solution {
public:
    
    void recurFunc(vector<int> &ds, vector<int> &nums, vector<int> &freq, vector<vector<int>> &res){
        if(ds.size() == nums.size()){
            res.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(freq[i]!=1){
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurFunc(ds, nums, freq, res);
                freq[i] = 0;
                ds.pop_back();
            }
        }
            
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        vector<int> freq(nums.size(), 0);
        recurFunc(ds, nums, freq, res);
        
        return res; 
    }
};