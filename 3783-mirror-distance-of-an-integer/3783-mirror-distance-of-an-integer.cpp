class Solution {
public:
    int mirrorDistance(int n) {
        int x=n;
        int y=0;
        while(x>0){
            int digit = x%10;
            y =y*10+digit;
            x/=10;
        }
        int ans = abs(n-y);
        return ans;
    }
};