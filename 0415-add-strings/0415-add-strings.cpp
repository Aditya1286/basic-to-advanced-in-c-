class Solution {
public:
    string addStrings(string num1, string num2) {

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int n1 = num1.size();
        int n2 = num2.size();
        int i = 0, j = 0;
        int carry = 0;

        string ans = "";

        while (i < n1 || j < n2) {
            int sum = carry;

            if (i < n1)
                sum += num1[i++] - '0';

            if (j < n2)
                sum += num2[j++] - '0';

            ans.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        if (carry)
            ans.push_back(carry + '0');

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
