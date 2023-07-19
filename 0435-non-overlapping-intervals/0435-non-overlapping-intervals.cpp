class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int res = 0;
        vector<int> prev = intervals[0];
        for(auto interval : intervals){
            if(interval[0]<prev[1])
                res++;
            else
                prev = interval;
        }
        
        return res-1;
    }
};