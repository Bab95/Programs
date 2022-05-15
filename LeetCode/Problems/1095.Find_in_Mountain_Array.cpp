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
        int low = 0;
        int high = mountainArr.length()-1;
        int size = high;
        int pivot = -1;
        while (low < high) {
            int mid = low + (high-low)/2;
            int element = mountainArr.get(mid);
            int prev = mountainArr.get(mid-1);
            int next = mountainArr.get(mid+1);
            /*
            if (target == element){
                return mid;
            }else if (target == prev){
                return mid-1;
            }else if(target == next) {
                return mid + 1;
            }
            */
            if (element > prev && element > next){
                pivot = mid;
                break;
            }else if (element > prev) {
                low = mid;
            }else{
                high = mid;
            }
            // cout <<"abckacn" << endl;
        }
        // cout << pivot << endl;
        int index = -1;
        int l = 0;
        int h = pivot;
        while (l <= h){
            int mid = l + (h-l)/2;
            int _mid = mountainArr.get(mid);
            if (_mid == target) {
                return mid;
            }else if (_mid > target) {
                h= mid-1;
            }else {
                l = mid + 1;
            }
            // cout <<"herhe2" << endl;
        }

        l = pivot + 1;
        h = size;
        while (l <= h) {
            int mid = l + (h-l)/2;
            int _mid = mountainArr.get(mid);
            if (_mid == target) {
                return mid;
            }else if (_mid < target) {
                h= mid-1;
            }else {
                l = mid + 1;
            }
            // cout <<"zfdk" << endl;
        }
        return -1;
    }
};
