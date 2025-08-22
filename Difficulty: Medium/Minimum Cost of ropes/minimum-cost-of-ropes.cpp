class Solution {
  public:
    int minCost(vector<int>& price) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i : price) {
            pq.push(i);
        }
        
        int ans = 0;
        while (pq.size() > 1) {
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            
            int sum = first + second;
            ans += sum;
            
            pq.push(sum);
        }
        
        return ans;
    }
};
