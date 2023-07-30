class Solution {
public:
    int mcm(string &s, int i, int j, vector<vector<int>> &t){
        if(i==j)
            return 1;
        
        if(t[i][j]!=-1)
            return t[i][j];
        
        int mini = INT_MAX;
        
        for(int k=i;k<j;k++)
            mini = min(mini, mcm(s,i,k,t)+mcm(s,k+1,j,t));
        
        return t[i][j] = (s[i] == s[j]) ? mini-1 : mini;;
    }
    
    int strangePrinter(string s) {
        int n= s.size();
        vector<vector<int>> t(n, vector<int>(n, -1));
        return mcm(s,0,n-1,t);
    }
};