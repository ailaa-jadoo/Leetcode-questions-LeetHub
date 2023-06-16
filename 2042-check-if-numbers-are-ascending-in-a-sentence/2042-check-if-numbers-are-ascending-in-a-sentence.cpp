class Solution {
public:
    bool areNumbersAscending(string s) {
        int prevNum = -1;
        int currNum = 0;
        int i=0;
        
        while(i<s.size()){
            if(isdigit(s[i])){
                currNum = 0;
                
                while(i<s.size() and isdigit(s[i])){
                    currNum = currNum*10 + (s[i]-'0');
                    i++;
                }
                if(currNum <= prevNum)
                    return false;
                
                prevNum = currNum;
            }
            else
                i++;
        }
        
        return true;
    }
    
};