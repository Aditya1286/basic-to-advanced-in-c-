class Solution {
public:
    string multiplyStrings(string &s1, string &s2) {

        bool negative = false;

        if (s1[0] == '-') {
            negative = !negative;
            s1 = s1.substr(1);
        }
        if (s2[0] == '-') {
            negative = !negative;
            s2 = s2.substr(1);
        }

        int k = 0;
        while (k < s1.size() && s1[k] == '0') k++;
        s1 = s1.substr(k);
        if (s1 == "") s1 = "0";

        k = 0;
        while (k < s2.size() && s2[k] == '0') k++;
        s2 = s2.substr(k);
        if (s2 == "") s2 = "0";

        if (s1 == "0" || s2 == "0")
            return "0";

        int n1 = s1.size();
        int n2 = s2.size();
        vector<int> result(n1 + n2, 0);

        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int pos2 = i + j + 1;
                int pos1 = i + j;

                int sum = mul + result[pos2];
                result[pos2] = sum % 10;
                result[pos1] += sum / 10;
            }
        }

        string ans = "";
        for (int num : result) {
            if (!(ans.empty() && num == 0))
                ans.push_back(num + '0');
        }

        if (ans == "") ans = "0";

        if (negative && ans != "0")
            ans = "-" + ans;

        return ans;
    }
};
