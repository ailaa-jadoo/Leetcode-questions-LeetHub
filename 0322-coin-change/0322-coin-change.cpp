class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        int n = coins.size();
        
        vector<vector<int>> t(n+1, vector<int>(sum+1, INT_MAX-1));
        
        for(int i=1;i<n+1;i++)
            t[i][0] = 0;
        
        // if(n==1){
        //     if(sum>coins[0] and sum%coins[0]!=0)
        //         return -1;
        //     if(sum==0)
        //         return 0;
        //     if(sum<coins[0] and sum==1)
        //         return -1;
        //     if(sum%coins[0]==0)
        //         return sum/coins[0];
        // }
                
        for(int j=1;j<sum+1;j++){
            if(j%coins[0]==0)
                t[1][j] = j/coins[0];
            else
                t[1][j] = INT_MAX-1;
        }
        
        for(int i=1;i<n+1;i++)
            for(int j=1;j<sum+1;j++){
                if(coins[i-1]<=j)
                    t[i][j] = min(t[i][j-coins[i-1]] + 1, t[i-1][j]);
                else
                    t[i][j] = t[i-1][j];
            }
        
        return t[n][sum]==INT_MAX-1? -1: t[n][sum];
    }
};