class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int N = grid.size();
        queue<pair<int, int>> q;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(grid[i][j])
                    q.push({i, j});
        
        int res = -1;
        
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            res = grid[r][c];
            for(auto[dr, dc]:directions){
                int newR = r+dr;
                int newC = c+dc;
                if(min(newR, newC)>=0 and max(newR, newC)<N and grid[newR][newC]==0){
                    q.push({newR, newC});
                    grid[newR][newC] = grid[r][c]+1;
                }
            }
        }
        
        if(res>1)
            return res-1;
        else
            return -1;
    }
};