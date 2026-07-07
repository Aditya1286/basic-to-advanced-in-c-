class Solution {
private:
    long long rev(int num){
        int y=0;
        while(num!=0){
            int rem=num%10;
            y=y*10+rem;
            num/=10;
        }
        return y;
    }
    long long dick(int lawda){
        int x=lawda;
        int y=0;
        int sum = 0;
        while(x!=0){
            int rem=x%10;
            sum+=rem;
            if(rem!=0){
                y=y*10+rem;
            }
            x/=10;
        }
        long long num=rev(y);
        long long ans=num*sum;
        return ans;
        

    }
public:
    long long sumAndMultiply(int n) {
        return dick(n);
    }
};