class Solution {
public:
    int f(int idx, vector<int>& prices, int allowedToBuy, int n, vector<vector<int>>& dp){
        if(idx == n)
            return 0;
        
        if(dp[idx][allowedToBuy] != -1)
            return dp[idx][allowedToBuy];
        
        int profit = 0;
        
        if(allowedToBuy)
            profit = max(-prices[idx]+f(idx+1, prices, 0, n, dp), f(idx+1, prices, 1, n, dp));
        else
            profit = max(prices[idx]+f(idx+1, prices, 1, n, dp), f(idx+1, prices, 0, n, dp));
        
        return dp[idx][allowedToBuy] = profit;
            
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return f(0, prices, 1, n, dp);    
    }
};