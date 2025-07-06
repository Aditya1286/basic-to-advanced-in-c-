class FindSumPairs {
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;

        for (int num : nums2) {
            freq2[num]++;
        }
    }
    
    void add(int index, int val) {
        int old_val = nums2[index];
        freq2[old_val]--;
        nums2[index] += val;
        freq2[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for (int a : nums1) {
            int b = tot - a;
            if (freq2.count(b)) {
                ans += freq2[b];
            }
        }
        return ans;
    }
};
