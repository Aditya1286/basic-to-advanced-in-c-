class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
       int currentcount=0;
       int maxcount=0;
       int n=arr.size();
       for(int i=0;i<n;i++){
            if(arr[i]==1){
                currentcount++;
            }
            else{
                maxcount=max(maxcount,currentcount);
                currentcount=0;
            }
       } 
       maxcount=max(maxcount,currentcount);
       return maxcount;
    }
};