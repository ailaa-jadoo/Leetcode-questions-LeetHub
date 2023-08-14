class Solution {
public:
    int t[501][501]={};
    
    int memo(vector<int>& cost, vector<int>& time, int i, int wallRemain){
        if(wallRemain<=0)
            return 0;
        if(i>=cost.size())
            return 1000000000;
        if(t[i][wallRemain]!=0)
            return t[i][wallRemain];
        
        int notTake = memo(cost, time, i+1, wallRemain);
        int take = cost[i] + memo(cost, time, i+1, wallRemain- time[i] - 1);
        
        return t[i][wallRemain] = min(notTake, take);
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        return memo(cost, time, 0, time.size());
    }
};