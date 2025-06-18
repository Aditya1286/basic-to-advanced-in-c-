// User function template for C++

class Solution {
  public:
    int sumOfSeries(int n) {
        int sum=0;
        int res=asd(sum,n);
        return res;
    }
    int asd(int sum,int n){
        if(n==0)return sum;
        sum+=n*n*n;
        asd(sum,n-1);
    }
};