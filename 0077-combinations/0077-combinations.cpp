class Solution {
private:
    void solve(vector<int>& input,int index, int target, vector<int>& subset,vector<vector<int>>& res){
        if(subset.size()==target){
            res.push_back(subset);
            return;
        }
        if(index>=input.size())return;
        subset.push_back(input[index]);
        solve(input,index+1,target,subset,res);
        subset.pop_back();
        solve(input,index+1,target,subset,res);
    }
public:
    vector<vector<int>> combine(int n, int target) {
        vector<int> input;
        for(int i=1;i<=n;i++){
            input.push_back(i);
        }
        vector<vector<int>> res;
        vector<int> subset;
        solve(input,0,target,subset,res);
        return res;
    }
};