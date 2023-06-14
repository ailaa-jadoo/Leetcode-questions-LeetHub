class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        std::string result;
        result.reserve(s.size() + spaces.size()); // Reserve space for the final result

        int prevIndex = 0;
        for (int space : spaces) {
            result += s.substr(prevIndex, space - prevIndex); // Append substring without space
            result += ' '; // Append the space
            prevIndex = space; // Update the previous index
        }

        result += s.substr(prevIndex); // Append the remaining substring

        return result;
    }
};