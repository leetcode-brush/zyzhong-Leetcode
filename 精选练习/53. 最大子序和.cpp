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

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int _sum = nums[0];
        int _max = nums[0];  // 存在全为负数的情况
        for (int i = 1; i < nums.size(); i++) {
            if (_sum < 0)
                _sum = nums[i];
            else 
                _sum += nums[i];
            _max = max(_sum, _max);
        }
        return _max;
    }
};