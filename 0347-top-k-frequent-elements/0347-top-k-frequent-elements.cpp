class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto num : nums) freq[num]++;
        
        vector<vector<int>> buckets(nums.size()+1);
        for (auto [a, b] : freq)
            buckets[b].push_back(a);
        
        vector<int> res;
        for (int i = nums.size(); k; i--) {
            for (auto a : buckets[i]) {
                res.push_back(a);
                k--;
            }
        }
        
        return res;
    }
};

// https://leetcode.com/problems/top-k-frequent-elements/discuss/1336643/C%2B%2B-Two-Short-Solutions-O(nlogn)-Map%2BQueue-O(n)-Bucket-Sort