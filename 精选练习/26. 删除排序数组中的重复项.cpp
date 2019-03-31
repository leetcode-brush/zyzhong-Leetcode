class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 0) return 0;
        int s = 0;
        for (int f = 0; f < nums.size(); f++) {
            if (nums[f] != nums[s])
                nums[++s] = nums[f];
        }
        return ++s;
    }
};