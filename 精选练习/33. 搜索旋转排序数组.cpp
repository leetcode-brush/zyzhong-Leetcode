// 如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[high]) {
                if (nums[mid] < target && nums[high] >= target) low = mid + 1;
                else high = mid - 1;
            } else {
                if (nums[mid] > target && nums[low] <= target) high = mid - 1;
                else low = mid + 1;
            }
        }
        return -1;
    }
};