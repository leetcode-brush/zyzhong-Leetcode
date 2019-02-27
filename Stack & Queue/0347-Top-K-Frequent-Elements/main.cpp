class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> record;
        for (int i = 0; i < nums.size(); i++)
            record[nums[i]] ++;
        
        vector<pair<int, int>> vec;
        for (auto iter = record.begin(); iter != record.end(); ++iter)
            vec.push_back(make_pair(iter->second, iter->first)) ;
        sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        
        vector<int> res;
        for (int i = 0; i < k; i++)
            res.push_back(vec[i].second);
        
        return res; 
    }
};