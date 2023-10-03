class Solution {
public:
    int fn(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }
    
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int count = 0;
        unordered_map<int, int> diffCount;

        for (int num : nums) {
            int diff = num - fn(num);

            if (diffCount.find(diff) != diffCount.end())
                count = (count + diffCount[diff]) % MOD;

            diffCount[diff]++;
        }

        return count;
    }
};