class Solution {
public:
    string sortSentence(string s) {
        istringstream iss(s);
        string word;
        vector<pair<int, string>> words;

        while (iss >> word) {
            int num = word.back() - '0';
            word.pop_back();
            words.emplace_back(num, word);
        }

        sort(words.begin(), words.end());

        string result;
        for (const auto& pair : words) {
            result += pair.second + " ";
        }

        result.pop_back(); // Remove the trailing space

        return result;
    }
};