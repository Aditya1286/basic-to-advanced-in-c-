class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        int n=arr.size();
        int low =0; 
        int boat = 0;
        int high =n-1;
        sort(arr.begin(),arr.end());
        while(low<=high){
            int remain=limit-arr[high--];
            boat++;
            if(low<=high && remain>=arr[low]){
                low++;
            }
        }
        return boat;
    }
};