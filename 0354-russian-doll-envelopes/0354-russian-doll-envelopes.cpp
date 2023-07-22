class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        vector<int> piles;
        for (int i = 0; i < n; i++) {
            int height = envelopes[i][1];
            auto it = lower_bound(piles.begin(), piles.end(), height);
            if (it == piles.end())
                piles.push_back(height);
            else
                *it = height;
        }

        return piles.size();
    }
};