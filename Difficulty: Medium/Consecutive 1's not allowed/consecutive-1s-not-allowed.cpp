// User function template for C++
class Solution {
  public:
    #define ll long long
    ll countStrings(int n) {
        ll zeroend = 1;
        ll oneend = 1;
        ll sum = zeroend + oneend;
        int i = 2;
        while(i <= n) {
            oneend = zeroend;
            zeroend = sum;
            sum = zeroend + oneend;
            i++;
        }
        return sum;
    }
};
