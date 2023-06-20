class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum<target)
            return 0;
        
        int left = 0, right =0, currSumOfWindow=0;
        int res=1e5+1;
        
        for(right = 0; right < nums.size(); right++) {
            currSumOfWindow += nums[right];

            while (currSumOfWindow >= target) {
                res = min(res, right - left + 1);
                currSumOfWindow -= nums[left];
                left++;
            }
        }
        
        return res;
    }
};