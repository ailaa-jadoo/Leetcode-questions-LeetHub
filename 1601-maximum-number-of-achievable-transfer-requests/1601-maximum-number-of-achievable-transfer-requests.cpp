class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        int maxAchievable = 0;

        for (int mask = 0; mask < (1 << m); mask++) {
            vector<int> count(n, 0);
            int numRequests = 0;

            for (int i = 0; i < m; i++) {
                if ((mask & (1 << i)) != 0) {
                    int from = requests[i][0];
                    int to = requests[i][1];
                    count[from]--;
                    count[to]++;
                    numRequests++;
                }
            }

            bool isValid = true;
            for (int i = 0; i < n; i++) {
                if (count[i] != 0) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                maxAchievable = max(maxAchievable, numRequests);
            }
        }

        return maxAchievable;
    }
};
