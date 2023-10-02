class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = INT_MIN, cnt = 0, res=1;
        
        for(int x:nums)
            maxi = max(maxi, x);
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi)
                cnt++;
            else
                cnt = 0;
            
            res = max(res, cnt);
        }
        
        return res;
    }
};