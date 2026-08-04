class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=nums[0];
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(ans!=nums[i]){
                while(ans!=nums[i]){
                    res.push_back(ans++);
                }
            }
            ans++;
        }
        return res;
    }
};