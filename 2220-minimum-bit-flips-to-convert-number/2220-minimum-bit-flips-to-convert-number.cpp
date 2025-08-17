class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ds=start^goal;
        int count=0;
        while(ds!=0){
            if(ds%2==1)count++;
            ds/=2;
        }
        return count;
    }
};