class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> ahead(2, 0);
        vector<int> curr(2, 0);
        
        ahead[0] = ahead[1] = 0;
        
        for(int idx =n-1;idx>=0;idx--){
            for(int allowedToBuy=0;allowedToBuy<=1;allowedToBuy++){
                int profit = 0;
        
                if(allowedToBuy)
                    profit = max(-prices[idx]+ahead[0] , ahead[1]);
                else
                    profit = max(prices[idx]-fee+ahead[1] , ahead[0]);

                curr[allowedToBuy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];   
    }
};