class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string firstPair = (x > y) ? "ab" : "ba";
        int firstScore = max(x, y);
        string secondPair = (x > y) ? "ba" : "ab";
        int secondScore = min(x, y);

        int total = 0;
        stack<char> stk;

        auto removePair = [&](const string& str, string pair, int score) {
            string temp;
            for (char c : str) {
                if (!temp.empty() && temp.back() == pair[0] && c == pair[1]) {
                    temp.pop_back();
                    total += score;
                } else {
                    temp.push_back(c);
                }
            }
            return temp;
        };

        string afterFirst = removePair(s, firstPair, firstScore);

        removePair(afterFirst, secondPair, secondScore);

        return total;
    }
};
