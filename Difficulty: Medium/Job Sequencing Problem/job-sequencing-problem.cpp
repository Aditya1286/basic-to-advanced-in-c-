#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int findParent(int slot, vector<int> &parent) {
        if (parent[slot] == slot)
            return slot;
        return parent[slot] = findParent(parent[slot], parent);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs;
        
        for (int i = 0; i < n; i++)
            jobs.push_back({profit[i], deadline[i]});
        
        sort(jobs.begin(), jobs.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.first > b.first;
        });
        
        int maxDeadline = 0;
        for (auto &job : jobs)
            maxDeadline = max(maxDeadline, job.second);
        
        vector<int> parent(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++)
            parent[i] = i;
        
        int jobCount = 0;
        int maxProfit = 0;
        
        for (int i = 0; i < n; i++) {
            int availableSlot = findParent(jobs[i].second, parent);
            
            if (availableSlot > 0) {
                maxProfit += jobs[i].first;
                jobCount++;
                parent[availableSlot] = findParent(availableSlot - 1, parent);
            }
        }
        
        return {jobCount, maxProfit};
    }
};
