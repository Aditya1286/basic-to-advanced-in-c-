class Solution {
private:
    bool dfs(vector<int> arr,int length, vector<int>& sides, int index){
        if(index==arr.size()){
            return true;
        }
        for(int i=0;i<4;i++){
            if(sides[i]+arr[index]<=length){
                sides[i]+=arr[index];
                if(dfs(arr,length,sides,index+1))return true;
                sides[i]-=arr[index];
            }
            if(sides[i]==0)break;
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0)return false;
        int length=sum/4;
        vector<int> sides(4,0);
        sort(matchsticks.rbegin(),matchsticks.rend());
        return dfs(matchsticks,length,sides,0);
    }
};