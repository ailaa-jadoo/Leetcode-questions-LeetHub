class Solution {
public:
    
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i>=0 and i<n and j>=0 and j<m and grid[i][j]==0)
            return true;
        
        return false;
    }
    
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid){
        grid[i][j]=1;
        
        int ax[4]={1, -1, 0, 0};
        int ay[4]={0, 0, 1, -1};
        
        for(int k=0;k<4;k++){
            int ni = i+ax[k];
            int nj = j+ay[k];
            
            if(isValid(ni, nj, n, m , grid)){
                dfs(ni, nj, n, m , grid);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(i*j==0 or i==n-1 or j==m-1)
                    if(grid[i][j] == 0)
                        dfs(i, j, n, m, grid);

        int res=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                    if(grid[i][j] == 0){
                        res++;
                        dfs(i, j, n, m, grid);
                    }
        
        return res;
    }
};