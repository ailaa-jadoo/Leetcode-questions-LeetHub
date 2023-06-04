class Solution {
public:
    
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit) {
        visit[node] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] && !visit[i]) {
                dfs(i, isConnected, visit);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numOfComponents = 0;
        vector<bool> visit(isConnected.size());
        
        for(int i=0;i<isConnected.size();i++){
            if(!visit[i]){
                numOfComponents++;
                dfs(i, isConnected, visit);
            }
        }
        
        return numOfComponents;
    }
};