class Solution {
public:
    int maxArea(vector<int>& height) {
        int _max = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            _max = max(_max, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) l++;
            else r--;
        }
        return _max;
    }
};