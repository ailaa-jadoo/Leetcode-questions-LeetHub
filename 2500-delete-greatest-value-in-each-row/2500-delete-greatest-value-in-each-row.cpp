class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++){
            sort(grid[i].begin(), grid[i].end());
        }
        
        if(m==1 and n==1)
            return grid[0][0];
        if(m==1)
            return accumulate(grid[0].begin(), grid[0].end(), 0);
        
        
        int maxSum=0;
        
        for (int col = n - 1; col >= 0; col--) {
            int currMax = INT_MIN;

            for (int row = 0; row < m; row++) 
                currMax = max(currMax, grid[row][col]);

            maxSum += currMax;
        }
                
        return maxSum;
    }
};
