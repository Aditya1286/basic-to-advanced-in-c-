void insertSorted(stack<int>& s, int element) {
    if (s.empty() || s.top() <= element) {
        s.push(element);
        return;
    }
    int top = s.top();
    s.pop();
    insertSorted(s, element);
    s.push(top);
}

void SortedStack::sort() {
    if (s.empty()) return;

    int top = s.top();
    s.pop();
    sort();
    insertSorted(s, top);
}
