class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // {{r, c}, t}
        queue<pair<pair<int,int>,int>> q;
        int fresh = 0 , afterfresh = 0; 
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j] = 2;
                    q.push({{i,j}, 0});
                }
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        
        int time=0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time , t);
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr = r+drow[i];
                int nc = c+dcol[i];
                
                if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc]==1 and vis[nr][nc]==0){
                    vis[nr][nc] = 2;
                    q.push({{nr, nc}, t+1});
                    afterfresh++;
                    cout<<"Hello";
                }
            }
        }
        
        if(fresh!=afterfresh)
            return -1;
        
        return time;
    }
};