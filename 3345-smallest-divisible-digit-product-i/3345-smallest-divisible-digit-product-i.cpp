class Solution {
private:
    int digprod(int n){
        int ans=1;
        while(n!=0){
            int rem=n%10;
            ans*=rem;
            n/=10;
        }
        return ans;
    }
public:
    int smallestNumber(int n, int t) {
        while(true){
            int pod=digprod(n);
            if(pod%t==0)return n;
            n++;
        }
        return -1;
    }
};