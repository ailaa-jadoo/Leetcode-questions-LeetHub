class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int n = nums.size();
        int xorBeautyValue = 0;

        for (int bit = 30; bit >= 0; bit--) {
            int count = 0;

            for (int i = 0; i < n; i++) {
                if (nums[i] & (1 << bit))
                    count++;
            }

            xorBeautyValue = (xorBeautyValue << 1) | (count % 2);
        }

        return xorBeautyValue;
    }
};