// 排序 时间复杂度O(nlogn) 空间复杂度O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() >> 1];
    }
};

// Hash Table 时间复杂度O(n) 空间复杂度O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int thres = nums.size() >> 1;
        unordered_map<int, int> m;
        for (auto v : nums) {
            m[v]++;
            if (m[v] > thres)
                return v;
        }
        return -1;
    }
};

// Moore Voting 时间复杂度O(n) 空间复杂度O(1)
// 从第一个数开始count=1，遇到相同的就加1，遇到不同的就减1，减到0就重新换个数开始计数，总能找到最多的那个
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int tmp = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] ^ tmp) {
                if (--cnt == 0)
                    tmp = nums[i + 1];
            } else {
                cnt++;
            }
        }
        return tmp;
    }
};