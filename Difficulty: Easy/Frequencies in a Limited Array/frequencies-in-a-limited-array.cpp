class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    vector<int> frequencyCount(vector<int>& arr) {
        vector<int> count;
        unordered_map<int,int> ast;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>=1 and arr[i]<=n){
                ast[arr[i]]++;
            }
        }
        for(int i=1;i<=n;i++){
            count.push_back(ast[i]);
        }
        return count;
    }
};
