class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> t;
        t[0] = 0;

        for (int x : rods) {
            unordered_map<int, int> cur_t = t;
            for (auto it = cur_t.begin(); it != cur_t.end(); ++it) {
                int d = it->first;
                int y = it->second;

                t[d + x] = max(t[d + x], y);
                t[abs(d - x)] = max(t[abs(d - x)], y + min(d, x));
            }
        }

        return t[0];
    }
};