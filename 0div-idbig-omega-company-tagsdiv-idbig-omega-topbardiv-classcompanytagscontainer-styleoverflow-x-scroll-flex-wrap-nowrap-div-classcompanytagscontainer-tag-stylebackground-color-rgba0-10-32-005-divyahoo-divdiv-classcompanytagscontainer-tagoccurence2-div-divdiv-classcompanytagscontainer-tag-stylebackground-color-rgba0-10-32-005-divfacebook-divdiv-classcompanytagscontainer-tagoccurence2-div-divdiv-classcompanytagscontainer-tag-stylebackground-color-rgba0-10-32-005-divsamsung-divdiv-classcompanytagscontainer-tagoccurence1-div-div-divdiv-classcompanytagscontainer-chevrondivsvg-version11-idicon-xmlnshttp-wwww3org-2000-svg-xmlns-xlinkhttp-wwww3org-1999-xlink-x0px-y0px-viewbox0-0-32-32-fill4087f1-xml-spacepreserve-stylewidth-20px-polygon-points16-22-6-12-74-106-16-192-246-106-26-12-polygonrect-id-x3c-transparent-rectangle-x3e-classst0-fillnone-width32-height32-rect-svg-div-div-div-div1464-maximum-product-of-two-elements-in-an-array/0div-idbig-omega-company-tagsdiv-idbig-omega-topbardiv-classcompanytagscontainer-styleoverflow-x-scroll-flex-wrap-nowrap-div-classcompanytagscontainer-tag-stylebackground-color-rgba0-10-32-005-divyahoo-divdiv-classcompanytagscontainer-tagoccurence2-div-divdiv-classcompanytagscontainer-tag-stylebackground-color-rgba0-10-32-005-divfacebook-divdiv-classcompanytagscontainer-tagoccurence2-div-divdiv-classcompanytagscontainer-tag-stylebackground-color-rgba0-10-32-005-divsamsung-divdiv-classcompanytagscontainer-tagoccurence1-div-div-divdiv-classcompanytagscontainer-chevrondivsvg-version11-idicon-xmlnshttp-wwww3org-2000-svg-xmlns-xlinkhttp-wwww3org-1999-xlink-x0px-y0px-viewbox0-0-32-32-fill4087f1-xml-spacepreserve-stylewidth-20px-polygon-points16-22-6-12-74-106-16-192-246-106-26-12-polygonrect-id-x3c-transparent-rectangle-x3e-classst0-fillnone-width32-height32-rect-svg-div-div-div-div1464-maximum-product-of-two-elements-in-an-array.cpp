class Solution {
public:
    int maxProduct(vector<int>& nums) {
           int n = nums.size();
        
        int firstMax  = 0;
        int secondMax = 0;
        
        
        for(int i = 0; i<n; i++) {
            
            if(nums[i] > firstMax) {
                secondMax = firstMax;
                firstMax = nums[i];
            } else {
                secondMax = max(secondMax, nums[i]);
            }
            
        }
        
        return (firstMax-1)*(secondMax-1);
    }
};