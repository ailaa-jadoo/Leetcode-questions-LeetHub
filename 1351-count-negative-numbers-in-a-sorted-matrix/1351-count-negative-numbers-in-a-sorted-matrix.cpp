class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int res=0;
        
        for(int i=0;i<grid.size();i++){
            sort(grid[i].begin(), grid[i].end());
            
            int firstPos = lower_bound(grid[i].begin(), grid[i].end(), 1) - grid[i].begin();
            int firstZero = lower_bound(grid[i].begin(), grid[i].end(), 0) - grid[i].begin();

            res+= min(firstPos, firstZero);
        }
        
        return res;
    }
};