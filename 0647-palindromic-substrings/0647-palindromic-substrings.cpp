class Solution {
public:
    int countSubstrings(string str) {
        int count = 0;
        int n = str.length();

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && str[left] == str[right]) {
                count++;
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            expandAroundCenter(i, i);
            expandAroundCenter(i, i + 1);
        }

        return count;
    }
};