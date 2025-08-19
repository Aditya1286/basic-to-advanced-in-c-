class Solution {
public: 
    int lessthan(vector<int> nums,int k){
        int l=0,r=0,count=0;
        map<int, int> mp;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return lessthan(nums,k)-lessthan(nums,k-1);
    }
};