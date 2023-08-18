class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        
        for(vector<int> road : roads){
            int u = road[0];
            int v = road[1];
            connected[u][v] = true, connected[v][u] = true;
            degree[u]++;
            degree[v]++;
        }
        
        int res = 0;
        
        for(int u=0;u<n;u++)
            for(int v=u+1;v<n;v++)
                res = max(res, degree[u]+degree[v]-connected[u][v]);

        return res;
    }
};