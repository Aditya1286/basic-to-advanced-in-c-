class Solution {
public:
    int numberOfSubarrays(vector<int>&nums,int k){
        return lessthan(nums,k)-lessthan(nums,k-1);
    }
    int lessthan(vector<int>& nums, int k) {
        int l = 0, count = 0, oddCount = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 == 1) {
                oddCount++;
            }

            while (oddCount > k) {
                if (nums[l] % 2 == 1) {
                    oddCount--;
                }
                l++;
            }

            count += r - l + 1;
        }
        return count;
    }
};
