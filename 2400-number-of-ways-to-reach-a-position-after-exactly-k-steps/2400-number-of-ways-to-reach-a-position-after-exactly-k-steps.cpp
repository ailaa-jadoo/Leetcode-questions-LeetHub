class Solution {
public:  
    
    long long count(int currPos, int target, vector<vector<int>> &dp, int k){
        if(k==0 and target == currPos)
            return 1;
        if(k==0)
            return 0;
        if(dp[currPos+1000][k] != -1)  //curPos+1000? aisa h ki minus karte karte max bhi -1000 jayega to usko 0or0+ rakhne ke liye1000 add kardiya h
            return dp[currPos+1000][k];
        long long a = count(currPos+1, target, dp, k-1)+count(currPos-1, target, dp, k-1);
        
        return dp[currPos+1000][k] = a%1000000007;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(4001, vector<int> (1001, -1));
        
        long long res = count(startPos, endPos, dp, k);
        return res%1000000007;
    }
};