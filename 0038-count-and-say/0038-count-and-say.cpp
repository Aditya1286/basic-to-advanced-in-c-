class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        
        for (int i = 1; i < n; ++i) {
            string nextResult = "";
            int count = 1;
            
            for (int j = 1; j < result.size(); ++j) {
                if (result[j] == result[j - 1]) {
                    count++;
                } else {
                    nextResult += to_string(count) + result[j - 1];
                    count = 1;
                }
            }
            
            nextResult += to_string(count) + result[result.size() - 1];
            result = nextResult;
        }
        
        return result;
    }
};
