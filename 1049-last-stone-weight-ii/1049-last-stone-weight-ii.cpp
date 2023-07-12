class Solution {
public:
    vector<int> dmpi(vector<int>& stones, int sum){
        int n = stones.size();
        vector<int> res;
        
        vector<vector<bool>> t(n+1, vector<bool>(sum+1, false));
        
        for(int i=0;i<n+1;i++)
            t[i][0] = true;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(stones[i-1]<=j)
                    t[i][j] = t[i-1][j-stones[i-1]] || t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        for(int j=0;j<sum+1; j++)
            if(t[n][j] == true)
                res.push_back(j);
        
        return res;
        
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<int> res = dmpi(stones, sum/2);
        
        int mini = INT_MAX;
        
        for(int i=0;i<res.size();i++)
            mini = min(mini, sum-2*res[i]);
        
        return mini;
    }
};