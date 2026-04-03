class Solution {
private:
    void dfs(vector<int>& num,int index,int target,vector<int>& subset,vector<vector<int>>& res){
        if(target==0){
            res.push_back(subset);
            return ;
        }
        if(index>=num.size() || target<0){
            return ;
        }
        subset.push_back(num[index]);
        dfs(num,index,target-num[index],subset,res);
        subset.pop_back();
        dfs(num,index+1,target,subset,res);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(candidates,0,target,subset,res);
        return res;
    }
};