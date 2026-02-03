/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int low=0;
        int high=mountainArr.length()-1;
        int n=mountainArr.length();
        while(low<high){
            int mid=low+(high-low)/2;
            int mid1=mountainArr.get(mid);
            int mid2=mountainArr.get(mid+1);
            if(mid1<mid2){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        int peak=low;
        //leftpart
         low=0;
         high=peak-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }
            else if(mountainArr.get(mid)<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
         low=peak;
         high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }
            if(mountainArr.get(mid)<target){
                high=mid-1;
            }
            else low=mid+1;
        }
        return -1;
    }
};