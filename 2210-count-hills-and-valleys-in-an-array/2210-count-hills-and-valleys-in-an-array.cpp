class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            } else {
                int j = i + 1;
                while (j != n && nums[i] == nums[j]) {
                    j++;
                }

                if (j != n && nums[i - 1] > nums[i] && nums[j] > nums[i]) {
                    ans++;
                } else if (j != n && nums[i - 1] < nums[i] && nums[j] < nums[i]) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
