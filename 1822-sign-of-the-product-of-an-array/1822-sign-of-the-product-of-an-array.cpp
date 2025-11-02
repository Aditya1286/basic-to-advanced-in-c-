class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count =0;
        for(int n:nums){
            if(n==0)return 0;
            if(n<0)count++;
        }
        if(count%2==0)return 1;
        return -1;
        
    }
};