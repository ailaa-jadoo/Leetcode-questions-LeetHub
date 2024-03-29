class Solution {
public:
    
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    bool canWalk(vector<vector<int>>& cells, int row, int col, int dayAt){
        vector<vector<bool>> grid(row, vector<bool>(col, 0));
        for(int i=0;i<dayAt;i++)
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        
        queue<pair<int, int>> q;
        
        for(int c=0;c<col;c++){
            if(grid[0][c] == 0){
                q.push({0, c});
                grid[0][c] = 1;
            }
        }
        
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            
            if(r == row-1)
                return true;
            
            for(int i=0;i<4;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];
                if(nr<0 or nr == row or nc<0 or nc == col or grid[nr][nc] == 1)
                    continue;
                grid[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
        
        
        return false;
    }    
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = cells.size(), res = 0;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            
            if(canWalk(cells, row, col, mid)){
                res = mid;
                left = mid+1;
            }
            else
                right = mid-1;
        }
        
        return res;
    }
};