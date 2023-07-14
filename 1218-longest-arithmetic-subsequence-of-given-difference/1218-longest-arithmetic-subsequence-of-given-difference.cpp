class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> lengths;
        int las = 1;
        for(auto e:arr)
            las = max(las, lengths[e]=1+lengths[e-difference]);
        
        return las;
    }
};