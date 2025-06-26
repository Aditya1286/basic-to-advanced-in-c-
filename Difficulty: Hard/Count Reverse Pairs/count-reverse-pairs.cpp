// User function Template for C++

class Solution {
  public:
    int reversePairCount = 0;

    void countPairs(vector<int>& arr, int low, int mid, int high) {
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)arr[i] > 2LL * arr[right]) {
                right++;
            }
            reversePairCount += (right - (mid + 1));
        }
    }

    void merge(vector<int>& arr, int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        vector<int> left(n1), right(n2);

        for (int i = 0; i < n1; i++) left[i] = arr[low + i];
        for (int i = 0; i < n2; i++) right[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = low;

        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) arr[k++] = left[i++];
            else arr[k++] = right[j++];
        }
        while (i < n1) arr[k++] = left[i++];
        while (j < n2) arr[k++] = right[j++];
    }

    void mergeSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            countPairs(arr, low, mid, high);
            merge(arr, low, mid, high);
        }
    }

    int countRevPairs(int n, vector<int> arr) {
        reversePairCount = 0;
        mergeSort(arr, 0, n - 1);
        return reversePairCount;
    }
};
