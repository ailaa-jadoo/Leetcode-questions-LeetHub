class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        
        int cnt = 1;
        while(ss >> word){
            if(word.substr(0, searchWord.size()) == searchWord)
                return cnt;
            else
                cnt++;
        }
        
        return -1;
    }
};