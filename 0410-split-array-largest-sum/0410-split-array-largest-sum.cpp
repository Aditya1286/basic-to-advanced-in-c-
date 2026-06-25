class Solution {
private:
    int asd(vector<int>&arr,int target){
        int count=1;
        int tar=0;
        for(int i=0;i<arr.size();i++){
            if(tar+arr[i]<=target){
                tar+=arr[i];
            }
            else{
                count++;
                tar=arr[i];
            }
        }
        return count;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=high-(high-low)/2;
            int x=asd(nums,mid);
            if(x>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;

    }
};