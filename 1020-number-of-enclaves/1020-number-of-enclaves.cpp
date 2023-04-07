class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>> q; 
        int n = grid.size(); 
        int m = grid[0].size(); 
        int vis[n][m];
        memset(vis, 0, sizeof(vis));
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(i*j==0 or i==n-1 or j==m-1)
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        vis[i][j]=1;
                    }
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, +0, -1}; 
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++){
                int nrow = row+delrow[k];
                int ncol = col+delcol[k];
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0 and grid[nrow][ncol]==1){
                    q.push({nrow, ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        
        int count =0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(vis[i][j]==0 and grid[i][j]==1)
                    count++;
        
        return count;
    }
};