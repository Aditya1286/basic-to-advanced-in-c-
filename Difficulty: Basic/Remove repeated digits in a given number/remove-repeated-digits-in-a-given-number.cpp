#include <vector>
using namespace std;

long long int modify(long long int N) {
    vector<int> res;
    long long int n = N;

    while (n != 0) {
        int rem = n % 10;
        if (res.empty() || res.back() != rem) {
            res.push_back(rem);
        }
        n = n / 10;
    }

    long long int as = 0;
    for (int i = res.size() - 1; i >= 0; i--) {
        as = as * 10 + res[i];
    }

    return as;
}
