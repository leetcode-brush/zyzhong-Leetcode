class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int start = 0;
        int end = nums.size( ) - 1;
        while (start < end) {
            if ((nums[start] + nums[end]) < target) {
                start++;
                continue;
            } else if ((nums[start] + nums[end]) > target) {
                end--;
                continue;
            } else {
                res.push_back(start);
                res.push_back(end);
                break;
            }
        }
        return res;
    }
};