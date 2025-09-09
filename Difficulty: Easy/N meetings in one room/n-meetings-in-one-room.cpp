#include <algorithm>
using namespace std;

class Solution {
public:
    class Data {
    public:
        int start;
        int end;
    };

    static bool comp(const Data& a, const Data& b) {
        return a.end < b.end;
    }

    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        Data arr[n];

        for (int i = 0; i < n; i++) {
            arr[i].start = start[i];
            arr[i].end = end[i];
        }

        sort(arr, arr + n, comp);

        int count = 1;
        int freetime = arr[0].end;

        for (int i = 1; i < n; i++) {
            if (arr[i].start > freetime) {
                count++;
                freetime = arr[i].end;
            }
        }

        return count;
    }
};
