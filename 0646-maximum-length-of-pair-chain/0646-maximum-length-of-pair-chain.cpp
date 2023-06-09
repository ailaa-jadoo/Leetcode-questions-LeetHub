class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        if(pairs.size() == 1)
            return 1;
        if(pairs.size() == 2){
            if(pairs[0][1]<pairs[1][0])
                return 2;
            else
                return 1;
        }
        
        sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        
        int curr = INT_MIN, res = 0;
        
        for(auto pair : pairs){
            if(curr<pair[0]){
                curr=pair[1];
                res++;
            }
        }
        
        return res;
    }
};