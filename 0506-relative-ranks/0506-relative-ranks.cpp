class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
         std::vector<std::string> answer(score.size());

        std::map<int, int, std::greater<int>> scoreToIndex;

        for (int i = 0; i < score.size(); i++) {
            scoreToIndex[score[i]] = i;
        }

        int rank = 1;
        for (const auto& pair : scoreToIndex) {
            int index = pair.second;
            if (rank == 1)
                answer[index] = "Gold Medal";
            else if (rank == 2)
                answer[index] = "Silver Medal";
            else if (rank == 3)
                answer[index] = "Bronze Medal";
            else
                answer[index] = std::to_string(rank);
            rank++;
        }

        return answer;
    }
};