// tabulation method

class Solution {
public: 
    int maxProfit(vector<int>& prices) {
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
                    profit = max(prices[idx]+ahead[1] , ahead[0]);

                curr[allowedToBuy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];    
    }
};


// Recursive

// class Solution {
// public:
//     int f(int idx, vector<int>& prices, int allowedToBuy, int n){
//         if(idx == n)
//             return 0;
        
//         int profit = 0;
        
//         if(allowedToBuy)
//             profit = max(-prices[idx]+f(idx+1, prices, 0, n), f(idx+1, prices, 1, n));
//         else
//             profit = max(prices[idx]+f(idx+1, prices, 1, n), f(idx+1, prices, 0, n));
        
//         return profit;
            
//     }
    
//     int maxProfit(vector<int>& prices) {
//         return f(0, prices, 1, prices.size());    
//     }
// };