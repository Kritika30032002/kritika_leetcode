class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
          int n = nums.size();
    int count = 1;
    for(int i = 1; i <n; i++)
    {
        if(nums[i] == nums[i-1])
        {
            continue;
        }
        
        else 
        {
            nums[count++] = nums[i];
        }
    }
    
    return count;
}
};