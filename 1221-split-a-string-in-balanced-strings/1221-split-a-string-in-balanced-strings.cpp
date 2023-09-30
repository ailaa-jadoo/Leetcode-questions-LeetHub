class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0;
        int res = 0;
        
        for(char ch : s){
            if(ch=='L')
                balance += -1;
            else
                balance += 1;
            
            if(balance == 0)
                res++;
        }
        
        return res;
    }
};