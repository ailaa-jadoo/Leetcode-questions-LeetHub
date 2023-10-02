class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.length();
        unordered_set<string> s;

        for (int i = 0; i < n; ) {
            if (!isdigit(word[i])) {
                i++;
                continue;
            }

            string temp;
            while (i < n && isdigit(word[i])) {
                temp += word[i];
                i++;
            }

            // Skip leading zeros
            while (!temp.empty() && temp[0] == '0')
                temp.erase(0, 1);

            s.insert(temp);
        }

        return s.size();
    }
};
