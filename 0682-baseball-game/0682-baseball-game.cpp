class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int ans=0;
        for(string &c:operations){
            if(c=="D"){
                int top=st.top();
                st.push(2*top);
                ans+=top*2;
            }
            else if(c=="+"){
                int top1=st.top();
                st.pop();
                int top2=st.top();
                st.pop();
                st.push(top2);
                st.push(top1);
                st.push(top1+top2);
                ans+=top1+top2;
            }
            else if(c=="C"){
                ans-=st.top();
                st.pop();
            }
            else{
                int num = stoi(c);
                st.push(num);
                ans += num;
            }
        }
        return ans;
    }
};