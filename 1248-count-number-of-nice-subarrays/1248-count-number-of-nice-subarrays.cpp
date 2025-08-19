class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
    int atmost(vector<int> arr,int k){
        int l=0,r=0,sum=0,count=0;
        while(r<arr.size()){
            sum += (arr[r]%2);
            while(sum>k){
                sum-=arr[l]%2;
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
};