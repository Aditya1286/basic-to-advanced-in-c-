class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({arr[i],i});
        }
        int swaps=0;
        sort(v.begin(),v.end());
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i] || v[i].second==i)continue;
            int cyclesize=0;
            int j=i;
            while(!visited[j]){
                visited[j]=true;
                j = v[j].second;
                cyclesize++;
            }
            if(cyclesize>1)swaps+=cyclesize-1;
        }
        return swaps;
    }
};