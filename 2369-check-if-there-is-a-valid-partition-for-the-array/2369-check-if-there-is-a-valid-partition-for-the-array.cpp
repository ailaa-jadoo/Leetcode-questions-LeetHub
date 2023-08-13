class Solution {
public:
    bool memo(vector<int>& nums, vector<int>& t, int i, int n){
        if(i>=n)
            return true;
        if(t[i]!=-1)
            return t[i];
        
        if(i+1<n and nums[i]==nums[i+1]){
            t[i] = memo(nums, t, i+2, n);
            if(t[i])
                return true;
            
            if(i+2<n and nums[i]==nums[i+2]){
                t[i] = memo(nums, t, i+3, n);
                if(t[i])
                    return true;
            }
        }
        
        if(i+2<n and nums[i+1]-nums[i]==1 and nums[i+2]-nums[i+1]==1){
            t[i] = memo(nums, t, i+3, n);
            if(t[i])
                return true;
        }
        
        return t[i] = false;
    }
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, -1);
        
        return memo(nums, t, 0, n);
    }
};