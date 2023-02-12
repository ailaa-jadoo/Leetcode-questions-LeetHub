class Solution {
public:
    
    long long res=0;
    
    long long dfs(vector<vector<int>> &v, int node, vector<int> &vis, int seats){
        vis[node]=true;
        
        long long count=1;
        for(int i=0;i<v[node].size();i++){
            
            int cur=v[node][i];
            if(!vis[cur])
                count+=dfs(v, cur, vis, seats);
        }
        
        long long x = count/seats;
        if(count%seats)
            x++;
        
        if(node!=0)
            res+=x;
        
        return count;
    }    
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        
        if(roads.size()==0)  return 0;
        
        res=0;
        int n = roads.size();
        vector<vector<int>> v(n+1);
        
        for(auto road : roads){
            int x = road[0], y = road[1];
            v[x].push_back(y);
            v[y].push_back(x);
        }
        
        vector<int> vis(n+1, 0);
        dfs(v, 0, vis, seats);
        
        return res;
    }
};