class Solution {
public:
    int parent[26];
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void uni(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (px < py) parent[py] = px;
        else parent[px] = py;
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (int i = 0; i < 26; i++) parent[i] = i;
        for (int i = 0; i < (int)s1.size(); i++) {
            uni(s1[i] - 'a', s2[i] - 'a');
        }
        string result = baseStr;
        for (int i = 0; i < (int)baseStr.size(); i++) {
            int c = baseStr[i] - 'a';
            result[i] = char('a' + find(c));
        }
        return result;
    }
};
