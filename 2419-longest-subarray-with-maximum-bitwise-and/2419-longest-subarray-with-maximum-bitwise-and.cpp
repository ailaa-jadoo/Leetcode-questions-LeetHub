class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = INT_MIN, cnt = 0, res=1;
        
        for(int x:nums)
            maxi = max(maxi, x); //taking maxi value to have highest set bits
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi)  //same number ke saath hi bit-wise AND largest hota hai
                cnt++;
            else
                cnt = 0;
            
            res = max(res, cnt);
        }
        
        return res;
    }
};