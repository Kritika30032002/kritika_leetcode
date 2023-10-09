class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int last = lower_bound(nums.begin(), nums.end(), target+1) - nums.begin() - 1;
        if(start < nums.size() && nums[start] == target){
            return {start, last};
        }
        return {-1, -1};
    }
};