class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        vector<int> nums(len);
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums.begin());
        if (len & 1)
            return nums[len / 2];
        else
            return (nums[len / 2] + nums[len / 2 - 1]) * 0.5;
    }
};