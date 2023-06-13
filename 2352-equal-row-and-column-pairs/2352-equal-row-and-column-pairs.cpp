class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> mp;
        
        int res=0;
        
        for(int i=0;i<n;i++)
            mp[grid[i]]++;
        
        for(int j=0;j<n;j++){
            vector<int> v;
            for(int i=0;i<n;i++)
                v.push_back(grid[i][j]);
            
            res += mp[v];
        }
        
        return res;
    }
};