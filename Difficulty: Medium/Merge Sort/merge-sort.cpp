class Solution {
  public:
    void mergeSort(vector<int>& arr, int left, int right) {
        if(left<right){
            int mid=left+((right-left)/2);
            mergeSort(arr,left,mid);
            mergeSort(arr,mid+1,right);
            merge(arr,left,mid,right);
        }
    }
    void merge(vector<int> &arr,int left,int mid,int right){
        int n1=mid-left+1;
        int n2=right-mid;
        vector<int> li(n1),ri(n2);
        for(int i=0;i<n1;i++){
            li[i]=arr[left+i];
        }
        for(int j=0;j<n2;j++){
            ri[j]=arr[mid+j+1];
        }
        int i=0,j=0,k=left;
        while(i<n1 && j<n2){
            if(li[i]<ri[j]){
                arr[k]=li[i];
                i++;
            }
            else{
                arr[k]=ri[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            arr[k]=li[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k]=ri[j];
            k++;
            j++;
        }
    }
};