class Solution {
public:
    int countOdds(int low, int high) {
        
        int count=0;
        //int low_odd, high_odd;
    
        low%2==0? low = low+1 : low = low;
        
        high%2==0? high = high-1 : high = high;
        
        for(int i=low;i<=high;i+=2)
            count++;
        
        return count;
    }
};