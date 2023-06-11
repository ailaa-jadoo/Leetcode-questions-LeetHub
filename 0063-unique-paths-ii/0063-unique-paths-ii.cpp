class Solution {
public:
    
    int paths(int m, int n, int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        if(i==m-1 and j==n-1)
            return 1;
        if(i>=m or j>=n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(obstacleGrid[i][j]==1)
            return 0;
        else{
            return dp[i][j] = paths(m,n,i+1,j,obstacleGrid,dp)+paths(m,n,i,j+1,obstacleGrid,dp);
        }
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        
        if(obstacleGrid[m-1][n-1])
            return 0;
        
        return paths(m,n,0,0,obstacleGrid,dp);
    }
};