class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> prefixCount(security.size() + 1, 0); 
        vector<int> suffixCount(security.size() + 1, 0); 

        // prefix
        for (int i = 1; i < n; i++) 
            if (security[i] <= security[i - 1]) 
                prefixCount[i] = prefixCount[i - 1] + 1; 

        // suffix 
        for (int i = n - 2; i >= 0; i--) 
            if (security[i] <= security[i + 1]) 
                suffixCount[i] = suffixCount[i + 1] + 1; 

        vector<int> res; 
        
        for (int i = max(0, time); i < (n - time); i++) 
            if (prefixCount[i] >= time && suffixCount[i] >= time) 
                res.push_back(i);

        return res;
    }
};