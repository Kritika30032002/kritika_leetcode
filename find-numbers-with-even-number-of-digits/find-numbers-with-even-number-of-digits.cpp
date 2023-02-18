class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            if((n>=10 && n<=99) || (1000<=n && n<=9999) || (100000<=n && n<=999999)){
                ans++;
            }
        }
        return ans;
    }
};