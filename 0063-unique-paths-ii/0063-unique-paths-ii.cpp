class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> t(n+1, vector<int>(m+1, 0));
        t[1][0] = 1;
        
        for(int i=1;i<n+1;i++)
            for(int j=1;j<m+1;j++)
                if(grid[i-1][j-1]!=1)
                    t[i][j] = t[i-1][j] + t[i][j-1];
        
        return t[n][m];
    }
};