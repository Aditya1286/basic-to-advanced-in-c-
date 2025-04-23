class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> cnt(50);
        for(int i=1;i<=n;i++){
            int s=0,x=i;
            while(x){s+=x%10; x/=10;}
            cnt[s]++;
        }
        int mx=*max_element(cnt.begin(), cnt.end());
        return count(cnt.begin(), cnt.end(), mx);
    }
};