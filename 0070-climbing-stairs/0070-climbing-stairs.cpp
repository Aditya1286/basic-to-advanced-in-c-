class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)return n;
        vector<int> stairs(n+1);
        stairs[1]=1;
        stairs[2]=2;
        for(int i=3;i<=n;i++){
            int a=stairs[i-2];
            int b=stairs[i-1];
            int c=a+b;
            stairs[i]=c;
        }
        return stairs[n];

    }
};