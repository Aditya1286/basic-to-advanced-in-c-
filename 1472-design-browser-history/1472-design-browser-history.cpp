class BrowserHistory {
public:
    stack<string> st;
    stack<string> forw;
    BrowserHistory(string homepage) {
        st.push(homepage);
    }
    
    void visit(string url) {
        st.push(url);
        forw=stack<string>();
    }
    
    string back(int steps) {
        steps = min(steps, (int)st.size() - 1);
        for(int i=0;i<steps;i++){
            string top=st.top();
            forw.push(top);
            st.pop();
        }
        return st.top();
    }
    
    string forward(int steps) {
        if(forw.size()<steps){
            steps=forw.size();
        }
        for(int i=0;i<steps;i++){
            string top=forw.top();
            forw.pop();
            st.push(top);
        }
        return st.top();
    }
};

