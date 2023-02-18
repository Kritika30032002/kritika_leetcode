class Solution {
     int ans=0;
        int count=0;
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)   {
                ans=max(ans,count);
                count=0;
            }
            else{
                count++;
            }
        }
        ans=max(ans,count);
        return ans;
    }
};