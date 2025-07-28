class Solution {
  public:
    bool checker(int index,int sum,vector<int> &arr,int target){
        if(sum>target)return false;
        if(index==arr.size()){
            if(sum==target)return true;
            else return false;
        }
        if(checker(index+1,sum+arr[index],arr,target)==true){
            return true;
        }
        if(checker(index+1,sum,arr,target)==true){
            return true;
        }
        return false;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        return checker(0,0,arr,sum);
    }
};