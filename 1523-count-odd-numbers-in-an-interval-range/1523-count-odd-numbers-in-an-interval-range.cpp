class Solution {
public:
    int countOdds(int low, int high) {
        
        int count=0;
        int low_odd, high_odd;
        
        if(low%2==0)
            low_odd = low+1;
        else
            low_odd = low;
        
        if(high%2==0)
            high_odd = high-1;
        else
            high_odd = high;
        
        for(int i=low_odd;i<=high_odd;i+=2)
            count++;
        
        return count;
    }
};