class Solution {
public:
    
    bool isAP(int &a2, int &a1, int &d){
        return a2-a1==d;
    }
    
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        
        if(arr.size()==2)
            return true;
        
        int currD = arr[0]-arr[1];
        
        for(int i=1;i<arr.size()-1;i++)
            if(!isAP(arr[i], arr[i+1], currD))
                return false;
        
        return true;
    }
};