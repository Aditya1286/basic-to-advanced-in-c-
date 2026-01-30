class Solution {
public:
    long long int mySqrt(long long int x) {
        if(x==1){
            return 1;
        }
        for(long long int i=1;i<x+1;i++){
            if(i*i==x){
                return i;
                break;
            }
            else if(i*i>x){
                return i-1;
                break;
            }
        }
    return 0;
    }
};