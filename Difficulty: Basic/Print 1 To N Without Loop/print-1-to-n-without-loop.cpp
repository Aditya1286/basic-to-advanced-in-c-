class Solution {
  public:
    void printNos(int n) {
       rec1(1,n);
    }
    void rec1(int count,int n){
        if(count>n)return;
        cout<<count<<" ";
        rec1(count+1,n);
    }
};