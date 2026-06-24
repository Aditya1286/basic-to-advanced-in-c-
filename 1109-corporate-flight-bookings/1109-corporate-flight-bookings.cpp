class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> arr(n+1,0);
        for(int i=0;i<bookings.size();i++){
            int l=bookings[i][0];
            int r=bookings[i][1];
            int v=bookings[i][2];
            if(r+1<n+1){
                arr[r+1]-=v;
            }
            arr[l]+=v;
        }
        for(int i=1;i<n+1;i++){
            arr[i]+=arr[i-1];
        }
        vector<int> num(n);
        for(int i=1;i<n+1;i++){
            num[i-1]=arr[i];
        }
        return num;
    }
};