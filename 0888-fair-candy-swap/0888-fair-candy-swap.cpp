class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aliceSum = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int bobSum = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        
        int delta = (bobSum - aliceSum)/2;
        set<int> st;
        
        for(int x : bobSizes)
            st.insert(x);
        
        for(int x:aliceSizes){
            if(st.count(x+delta))
               return {x, x+delta};
        }
        
        return {0, 0};
    }
};