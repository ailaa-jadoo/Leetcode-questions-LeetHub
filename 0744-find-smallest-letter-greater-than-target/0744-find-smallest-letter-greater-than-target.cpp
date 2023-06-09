class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target-letters[letters.size()-1]>=0)
            return letters[0];
        
        for(int i=0;i<letters.size();i++){
            if(letters[i]-target > 0){
                return letters[i];
                break;
            }
        }
        
        return letters[0];
    }
};