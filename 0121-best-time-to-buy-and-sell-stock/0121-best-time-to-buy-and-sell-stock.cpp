class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        int minn = prices[0];
        
        if(n<2) return 0;
        
        for(int i=1;i<n;i++){
            profit = max(profit, prices[i]-minn);
            minn = min(minn, prices[i]);
        }
        
        return profit;
    }
};