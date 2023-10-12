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
        int n = mountainArr.length();
        int left = 0, right = n - 1;
        
        // Binary search to find the peak of mountain.
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                left = mid + 1;
            else
                right = mid;
        }
        
        int peakIndex = left;
        
        // Binary search on the left of mountain.
        left = 0;
        right = peakIndex;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) == target)
                return mid;
            if (mountainArr.get(mid) < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        // Binary search on the right of mountain.
        left = peakIndex + 1;
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) == target)
                return mid;
            if (mountainArr.get(mid) > target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return -1; // Target not found.
    }
};