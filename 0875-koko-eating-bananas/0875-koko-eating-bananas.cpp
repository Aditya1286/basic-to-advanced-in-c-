class Solution {
private:
    long long koko(vector<int> nums , int k){
        long long count=0;
        for(int kela:nums){
            int time = (kela+k-1LL)/k;//ceil
            count+=time;
        }
        return count;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = *max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high){
            int mid = low+(high-low)/2;
            long long res=koko(piles,mid);

            if(res<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
            return ans;

    }
};