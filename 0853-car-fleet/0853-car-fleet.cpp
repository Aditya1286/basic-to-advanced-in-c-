class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,double>> cars;
        for(int i=0;i<n;i++){
            double time = (double)(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }
        sort(cars.rbegin(),cars.rend());
        int fleet=0;
        stack<double> st;
        for(auto &car:cars){
            double currentTime=car.second;
            if(st.empty() || currentTime>st.top()){
                st.push(currentTime);
            }
        }
        return st.size();
    }
};