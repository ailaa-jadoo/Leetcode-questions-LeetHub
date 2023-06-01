class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0)
           return -1;
        if(n==1 && grid[0][0]==0)
            return 1;
        if(n==1 && grid[0][0]==1)
            return -1;
        
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;
        q.push({1, {0, 0}});
        int dr[] = {-1, 0, 1, 0, 1, 1, -1, -1};
        int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for(int i=0;i<8;i++){
                int newR = r+dr[i];
                int newC = c+dc[i];
                
                if(newR>=0 and newR<n and newC>=0 and newC<n and grid[newR][newC]==0 and dis+1<dist[newR][newC]){
                    dist[newR][newC] = 1+dis;
                    if(newR == n-1 and newC == n-1)
                        return dis+1;
                    q.push({1+dis, {newR, newC}});
                }
            }
        }
        
        
        return -1;
    }
};