class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int price=INT_MAX;
        int maxprofit=0;
        for(int &it:prices){
            price=min(price,it);
            maxprofit=max(maxprofit,it-price);
        }
        return maxprofit;
    }
};