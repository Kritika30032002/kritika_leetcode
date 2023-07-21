class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        pair<int,int> dp[nums.size()+2];
        dp[0].first=1;
        dp[0].second=1;
        int mx=0;
        for(int i=1;i<nums.size();++i){
            dp[i].first=0;
            dp[i].second=1;
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i]){
                    if(dp[j].first>dp[i].first){
                        dp[i].first=dp[j].first;
                        dp[i].second=dp[j].second;
                    }else if(dp[j].first==dp[i].first){
                        dp[i].second+=dp[j].second;
                    }
                }
            }
            dp[i].first+=1;
            mx=max(dp[i].first, mx);
        }
        int ans=0;
        for(int i=0;i<nums.size();++i){
            if(mx==dp[i].first){
                ans+=dp[i].second;
            }
        }
        return ans;
    }
};