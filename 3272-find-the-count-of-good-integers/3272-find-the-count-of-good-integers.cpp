
long long fact[11];
void initFactorials() {
    fact[0] = 1;
    for (int i = 1; i <= 10; i++) {
        fact[i] = fact[i-1] * i;
    }
}

long long countPermutations(const array<int, 10> &f, int n) {
    long long total = fact[n];
    for (int d = 0; d < 10; d++) {
        total /= fact[f[d]];
    }
    if(f[0] == 0) return total;
    long long invalid = fact[n-1];
    array<int, 10> f2 = f;
    f2[0]--;
    for (int d = 0; d < 10; d++) {
        invalid /= fact[f2[d]];
    }
    return total - invalid;
}

int modFromString(const string &s, int k) {
    long long mod = 0;
    for(char ch: s) {
        mod = (mod * 10 + (ch - '0')) % k;
    }
    return mod;
}

string freqKey(const array<int, 10> &f) {
    string key;
    for (int d = 0; d < 10; d++) {
        key += to_string(f[d]) + ",";
    }
    return key;
}

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        initFactorials();
        unordered_map<string, long long> seen;
        long long result = 0;
        if(n == 0) return 0;
        if(n % 2 == 0) {
            int half = n / 2;
            int start = (int)pow(10, half - 1);
            int end = (int)pow(10, half) - 1;
            for (int i = start; i <= end; i++) {
                string left = to_string(i);
                string right = left;
                reverse(right.begin(), right.end());
                string pal = left + right;
                if(modFromString(pal, k) != 0) continue;
                array<int, 10> freq = {0};
                for (char ch : pal) {
                    freq[ch - '0']++;
                }
                string key = freqKey(freq);
                if(seen.find(key) == seen.end()){
                    long long cnt = countPermutations(freq, n);
                    seen[key] = cnt;
                }
            }
        } else {
            int half = (n + 1) / 2;
            int start = (int)pow(10, half - 1);
            int end = (int)pow(10, half) - 1;
            for (int i = start; i <= end; i++) {
                string s = to_string(i);
                string left = s.substr(0, s.size()-1);
                string right = left;
                reverse(right.begin(), right.end());
                string pal = s + right;
                if(modFromString(pal, k) != 0) continue;
                array<int, 10> freq = {0};
                for (char ch : pal)
                    freq[ch - '0']++;
                string key = freqKey(freq);
                if(seen.find(key) == seen.end()){
                    long long cnt = countPermutations(freq, n);
                    seen[key] = cnt;
                }
            }
        }
        for(auto &p : seen) {
            result += p.second;
        }
        return result;
    }
};