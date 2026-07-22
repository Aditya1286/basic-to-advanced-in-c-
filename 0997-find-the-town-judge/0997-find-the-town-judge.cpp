class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> incoming(N+1,0);
        vector<int> outgoing(N+1,0);
        for(auto &it:trust){
            outgoing[it[0]]++;
            incoming[it[1]]++;
        }
        for(int i=1;i<=N;i++){
            if(outgoing[i]==0 && incoming[i]==N-1)return i;
        }
        return -1;
    }
};