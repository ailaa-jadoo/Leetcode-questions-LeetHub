class Solution {
public:
    
    unordered_map<int, vector<int>> umap;
    int maxi=0, res =0;
    
    void dfs(int manager, vector<int>& informTime){
        maxi = max(res, maxi);
        
        for(auto employee: umap[manager]){
            res+=informTime[manager];
            dfs(employee, informTime);
            res-=informTime[manager];
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i=0;i<n;i++)
            if(manager[i]!=-1)
                umap[manager[i]].push_back(i); 
        
        dfs(headID, informTime);
        
        return maxi;
    }
};