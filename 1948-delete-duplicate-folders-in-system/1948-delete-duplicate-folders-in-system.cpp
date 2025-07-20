class Solution {
    struct Node {
        unordered_map<string, Node*> c;
    };
    unordered_map<string, int> cnt;
    unordered_map<Node*, string> sig;
    string dfs1(Node* u) {
        if (u->c.empty()) {
            sig[u] = "";
            return "";
        }
        vector<string> v;
        for (auto& [n, p] : u->c) {
            string sub = dfs1(p);
            v.push_back(n + sub);
        }
        sort(v.begin(), v.end());
        string s = "(";
        for (auto& x : v) s += x;
        s += ")";
        sig[u] = s;
        cnt[s]++;
        return s;
    }
    void dfs2(Node* u) {
        vector<string> toErase;
        for (auto& [n, p] : u->c) {
            if (!sig[p].empty() && cnt[sig[p]] > 1) {
                toErase.push_back(n);
            } else {
                dfs2(p);
            }
        }
        for (auto& n : toErase) {
            delete u->c[n];
            u->c.erase(n);
        }
    }
    void dfs3(Node* u, vector<string>& path, vector<vector<string>>& res) {
        for (auto& [n, p] : u->c) {
            path.push_back(n);
            res.push_back(path);
            dfs3(p, path, res);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node();
        for (auto& p : paths) {
            Node* cur = root;
            for (auto& d : p) {
                if (!cur->c.count(d))
                    cur->c[d] = new Node();
                cur = cur->c[d];
            }
        }
        dfs1(root);
        dfs2(root);
        vector<vector<string>> ans;
        vector<string> tmp;
        dfs3(root, tmp, ans);
        return ans;
    }
};
