class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0, res=INT_MIN;
        for(int g:gain){
            sum+=g;
            cout<<sum<<" ";
            res = max(res, sum);
        }
        
        return res>0 ? res : 0;
    }
};