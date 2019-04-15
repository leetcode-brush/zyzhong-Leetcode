class Solution {
    void two_sum(vector<int>& nums, int i, int target, vector<vector<int>> &res){
    int j = nums.size() - 1;
    int b = i - 1;
    while (i < j) {
        if (nums[i] + nums[j] == target) {
            res.push_back(vector<int>{nums[b], nums[i], nums[j]});
            //处理重复的情况
            i++;
            j--;
            while (i < j && nums[i] == nums[i - 1]) i++;
            while (i < j && nums[j + 1] == nums[j]) j--;
        } else {
            if (nums[i] + nums[j] < target)
                i++;
            else
                j--;
        }
    }
    return;
}
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
            if(i > 0 && nums[i - 1] == nums[i])
                continue;
            else
                two_sum(nums, i + 1, -nums[i], res);

        return res;
    }
};