class Solution {
public:
int maxAbsoluteSum(std::vector<int>& nums) {
    int n = nums.size();
    
    int maxSum = nums[0];
    int minSum = nums[0];
    int currMax = nums[0];
    int currMin = nums[0];
    int maxAbsSum = std::abs(nums[0]);
    
    for (int i = 1; i < n; i++) {
        currMax = std::max(nums[i], currMax + nums[i]);
        maxSum = std::max(maxSum, currMax);
        
        currMin = std::min(nums[i], currMin + nums[i]);
        minSum = std::min(minSum, currMin);
        
        maxAbsSum = std::max(maxAbsSum, std::max(std::abs(maxSum), std::abs(minSum)));
    }
    
    return maxAbsSum;
}
};


// https://youtu.be/XfCOrINuo4c    idea issne diya