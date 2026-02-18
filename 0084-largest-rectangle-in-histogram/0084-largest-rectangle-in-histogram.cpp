class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); 
        int n=heights.size();
        int maxarea = 0;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int height = heights[st.top()];
                st.pop();
                int right=i;
                int left = st.empty() ? -1 : st.top();
                int width=right-left-1;
                maxarea=max(maxarea,height*width);
            }
            st.push(i);
        }
        return maxarea;
    }
};