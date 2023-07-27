class Solution {
public:
    
    bool isPossible(vector<int> &batteries, long long time, int computers){
        long long totalTime = 0;
        for(int batterie : batteries){
            if(batterie<time)
                totalTime += batterie;
            else
                totalTime += time;
        }
        
        return totalTime>=(time*computers);
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 0, high = 0;
        
        int sz = batteries.size();
        for(int i = 0; i < sz; i++)
            high += batteries[i];

        // high = 1e14;
        
        long long res = 0;
        while(low<=high){
            long long mid = low + (high-low)/2;
            
            if(isPossible(batteries, mid, n)){
                res = mid;
                low = mid+1;
            }else
                high = mid-1;
        }
        
        
        return res;
    }
};