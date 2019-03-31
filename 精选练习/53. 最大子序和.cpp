class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++)
           nums[i] += max(nums[i - 1], 0);
        return *max_element(nums.begin(), nums.end());
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int _max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
           nums[i] += max(nums[i - 1], 0);
            _max = max(_max, nums[i]);
        }
        return _max;
    }
};