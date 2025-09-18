#include <bits/stdc++.h>
using namespace std;

class TaskManager {
    struct Task {
        int userId, taskId, priority;
        bool operator<(const Task& other) const {
            if (priority == other.priority) return taskId < other.taskId;
            return priority < other.priority;
        }
    };
    priority_queue<Task> pq;
    unordered_map<int, pair<int,int>> mp;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& t : tasks) {
            Task task{t[0], t[1], t[2]};
            pq.push(task);
            mp[t[1]] = {t[0], t[2]};
        }
    }
    void add(int userId, int taskId, int priority) {
        Task task{userId, taskId, priority};
        pq.push(task);
        mp[taskId] = {userId, priority};
    }
    void edit(int taskId, int newPriority) {
        auto [u, _] = mp[taskId];
        Task task{u, taskId, newPriority};
        pq.push(task);
        mp[taskId] = {u, newPriority};
    }
    void rmv(int taskId) {
        mp.erase(taskId);
    }
    int execTop() {
        while (!pq.empty()) {
            Task task = pq.top();
            if (mp.count(task.taskId) && mp[task.taskId].first == task.userId && mp[task.taskId].second == task.priority) {
                pq.pop();
                mp.erase(task.taskId);
                return task.userId;
            }
            pq.pop();
        }
        return -1;
    }
};
