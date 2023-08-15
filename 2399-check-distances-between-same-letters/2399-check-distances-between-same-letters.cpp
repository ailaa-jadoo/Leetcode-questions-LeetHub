class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> last_occurrence(26, -1);
    
        for (int i = 0; i < s.size(); ++i) {
            int letter_idx = s[i] - 'a';
            if (last_occurrence[letter_idx] != -1) {
                if (i - last_occurrence[letter_idx] - 1 != distance[letter_idx]) {
                    return false;
                }
            }
            last_occurrence[letter_idx] = i;
        }

        return true;
    }
};