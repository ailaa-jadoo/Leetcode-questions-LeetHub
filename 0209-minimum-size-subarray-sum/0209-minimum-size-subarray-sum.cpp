class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum<target)
            return 0;
        
        int minLength = INT_MAX;
        int currWinSum = 0;
        
        for(int right =0 ;right<nums.size();right++){
            currWinSum += nums[right];
            while(currWinSum >= target){
                minLength = min(minLength, right-left+1);
                currWinSum -= nums[left];
                left++;
            }
        }
        
        return minLength;
    }
};