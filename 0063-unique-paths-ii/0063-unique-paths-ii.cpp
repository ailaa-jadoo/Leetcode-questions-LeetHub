class Solution {
public:
    int memo(vector<vector<int>>& grid, vector<vector<int>>& t, int n, int m, int i, int j){
        if(i==n-1 and j==m-1)
            return 1;
        if(i>=n or j>=m)
            return 0;
        if(t[i][j] != -1)
            return t[i][j];
        if(grid[i][j]==1)
            return 0;
        else
            return t[i][j] = memo(grid, t, n, m, i+1, j) + memo(grid, t, n, m, i, j+1);
    }    

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> t(n+1, vector<int>(m+1, -1));
        
        if(grid[n-1][m-1] == 1)
            return 0;
        
        return memo(grid, t, n, m, 0, 0);
    }
};