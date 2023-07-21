// LCS of unique sorted array(b) and nums;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> st;
        for(int num:nums)
            st.insert(num);
        
        vector<int> b;
        for(int a : st)
            b.push_back(a);
        
        int n = nums.size();
        int m = b.size();
        
        vector<vector<int>> t(n+1, vector<int>(m+1, 0));
        
        for(int i=0;i<n+1;i++)
            t[i][0] = 0;
        
        for(int i=1;i<n+1;i++)
            for(int j=1;j<m+1;j++){
                if(nums[i-1] == b[j-1])
                    t[i][j] = 1+t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        
        return t[n][m];
    }
};