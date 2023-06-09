class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        
        if(target-letters[n-1]>=0)
            return letters[0];
        
        for(int i=0;i<n;i++){
            if(letters[i]-target > 0){
                return letters[i];
                break;
            }
        }
        
        return letters[0];
    }
};