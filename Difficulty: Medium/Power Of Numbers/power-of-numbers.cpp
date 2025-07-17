class Solution {
public:
    const int mod = 1e9 + 7;

    int reverse(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }

    double myPow(double x, long n) {
        if(n==0)return 1;
        if(n<0)return myPow(1/x,-n);
        if(n%2==0)return myPow(x*x,n/2);
        else return x*myPow(x*x,(n-1)/2);
    }

    int reverseExponentiation(int n) {
        int r = reverse(n);
        return myPow(n, r);
    }
};
