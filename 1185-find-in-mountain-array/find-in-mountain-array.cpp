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
    int findInMountainArray(int target, MountainArray &arr) {
        int n=arr.length(),l=0,r=n-1,mx=0;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(arr.get(mid)<arr.get(mid+1))
            {
                l=mid+1;
                mx=mid+1;
            }
            else
                r=mid;
        }
        l=0;
        r=mx;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(arr.get(mid)<target)
                l=mid+1;
            else if(arr.get(mid)>target)
                r=mid-1;
            else
                return mid;
        }
        l=mx;
        r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(arr.get(mid)>target)
                l=mid+1;
            else if(arr.get(mid)<target)
                r=mid-1;
            else
                return mid;
        }
        return -1;
    }
};