class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cnt = 0;
        int res = 0;
        
        for(int i = 0;i<nums.size();i++){
            if(i == 0)
                cnt++;
            else{
                if(nums[i]>nums[i-1])
                    cnt++;
                else{
                    res = max(res, cnt);
                    cnt = 1;
                }
            }
        }
        
        return max(cnt, res);
    }
};