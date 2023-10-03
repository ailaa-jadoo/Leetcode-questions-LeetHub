class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long count = 0;
        unordered_map<double, long long> ratioCount;

        for (const auto& rect : rectangles) {
            double ratio = (double)rect[0] / rect[1];

            if (ratioCount.find(ratio) != ratioCount.end()) 
                count += ratioCount[ratio];            

            ratioCount[ratio]++;
        }

        return count;
    }
};