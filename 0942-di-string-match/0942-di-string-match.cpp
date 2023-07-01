class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> res(n+1);
        
        int curr_max = n;
        int curr_min = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='I')
                res[i] = curr_min++;
            else
                res[i] = curr_max--;
        }
        
        if(s[n-1]=='I')
            res[n] = curr_max;
        else
            res[n] = curr_min;
        
        return res;
    }
};