class Solution {
public:
//     gpt ne chota karke diya
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int maxSum = nums[0];
        int minSum = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];
        int maxAbsSum = abs(nums[0]);

        for (int i = 1; i < n; i++) {
            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);

            currMin = min(nums[i], currMin + nums[i]);
            minSum = min(minSum, currMin);

            maxAbsSum = max(maxAbsSum, max(abs(maxSum), abs(minSum)));
        }

        return maxAbsSum;
    }
};