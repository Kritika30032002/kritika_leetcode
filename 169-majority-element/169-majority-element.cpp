class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int start=0;
        int end=nums.size()-1;
        sort(nums.begin(),nums.end());
        int mid=end/2;
        return nums[mid];
    }
};