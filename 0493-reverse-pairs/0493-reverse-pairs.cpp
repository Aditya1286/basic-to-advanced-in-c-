class Solution {
public:
    int count = 0;

    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);
        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }

        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }

    void countpairs(vector<int>& arr, int low, int mid, int high) {
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)arr[i] > 2LL * arr[right]) {
                right++;
            }
            count += (right - (mid + 1));
        }
    }

    void mergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            countpairs(arr, left, mid, right);
            merge(arr, left, mid, right);
        }
    }

    int reversePairs(vector<int>& nums) {
        count = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }
};
