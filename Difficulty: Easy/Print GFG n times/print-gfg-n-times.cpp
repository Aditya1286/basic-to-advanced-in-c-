class Solution {
  public:
    void printGfg(int N) {
        gfg(1,N);
    }
    void gfg(int count,int n){
        if(count>n)return;
        cout<<"GFG"<<" ";
        gfg(count+1,n);
    }
};
