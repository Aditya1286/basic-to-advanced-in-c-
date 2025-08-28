class Solution {
  public:
    int findMin(int n) {
        int count = 0;
        int coin[] = {1, 2, 5, 10};
        int m = sizeof(coin)/sizeof(coin[0]);
        for(int i = m-1; i >= 0; i--) {
            count += n / coin[i];
            n %= coin[i];
        }
        return count;
    }
};