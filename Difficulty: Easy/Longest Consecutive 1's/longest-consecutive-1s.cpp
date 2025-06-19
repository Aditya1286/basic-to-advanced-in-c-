#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int maxConsecutiveOnes(int N) {
        vector<int> arr = getBinary(N);
        int currentcount = 0;
        int maxcount = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 1) {
                currentcount++;
            } else {
                maxcount = max(maxcount, currentcount);
                currentcount = 0;
            }
        }
        maxcount = max(maxcount, currentcount);
        return maxcount;
    }

    vector<int> getBinary(int num) {
        vector<int> binary;
        if (num == 0) {
            binary.push_back(0);
            return binary;
        }

        while (num > 0) {
            binary.push_back(num % 2);
            num /= 2;
        }
        reverse(binary.begin(), binary.end());
        return binary;
    }
};
