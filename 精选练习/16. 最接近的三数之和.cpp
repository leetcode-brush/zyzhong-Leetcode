class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //assert(nums.size() >= 3);
        int res = nums[0] + nums[1] +nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int _sum = nums[i] + nums[j] + nums[k];
                if (abs(_sum - target) < abs(res - target))
                    res = _sum;
                if (_sum > target) k--;
                if (_sum < target) j++;
                if (_sum == target) return target;
            }
        }
        return res;
    }
};