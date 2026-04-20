class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        
        n = n % 14;
        if(n == 0) n = 14;  
        
        vector<int> temp = cells;
        int d = temp.size();

        for(int j = 0; j < n; j++){
            vector<int> ans(d, 0);

            for(int i = 0; i < d; i++){
                if(i == 0 || i == d-1) ans[i] = 0;
                else{
                    if(temp[i-1] == temp[i+1]){
                        ans[i] = 1;
                    }
                }
            }
            temp = ans;
        }
        return temp;
    }
};