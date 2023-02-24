class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        auto total = accumulate(begin(arr), end(arr), 0);
        if(total%3!=0)  return false;
        
        total/=3;
        int k=0,t=0;
        for(int i=0;i<arr.size();i++){
            k+=arr[i];
            if(k==total){
                t++;                
                k=0;
            }            
        }       
       
        return t>=3;
    }
};