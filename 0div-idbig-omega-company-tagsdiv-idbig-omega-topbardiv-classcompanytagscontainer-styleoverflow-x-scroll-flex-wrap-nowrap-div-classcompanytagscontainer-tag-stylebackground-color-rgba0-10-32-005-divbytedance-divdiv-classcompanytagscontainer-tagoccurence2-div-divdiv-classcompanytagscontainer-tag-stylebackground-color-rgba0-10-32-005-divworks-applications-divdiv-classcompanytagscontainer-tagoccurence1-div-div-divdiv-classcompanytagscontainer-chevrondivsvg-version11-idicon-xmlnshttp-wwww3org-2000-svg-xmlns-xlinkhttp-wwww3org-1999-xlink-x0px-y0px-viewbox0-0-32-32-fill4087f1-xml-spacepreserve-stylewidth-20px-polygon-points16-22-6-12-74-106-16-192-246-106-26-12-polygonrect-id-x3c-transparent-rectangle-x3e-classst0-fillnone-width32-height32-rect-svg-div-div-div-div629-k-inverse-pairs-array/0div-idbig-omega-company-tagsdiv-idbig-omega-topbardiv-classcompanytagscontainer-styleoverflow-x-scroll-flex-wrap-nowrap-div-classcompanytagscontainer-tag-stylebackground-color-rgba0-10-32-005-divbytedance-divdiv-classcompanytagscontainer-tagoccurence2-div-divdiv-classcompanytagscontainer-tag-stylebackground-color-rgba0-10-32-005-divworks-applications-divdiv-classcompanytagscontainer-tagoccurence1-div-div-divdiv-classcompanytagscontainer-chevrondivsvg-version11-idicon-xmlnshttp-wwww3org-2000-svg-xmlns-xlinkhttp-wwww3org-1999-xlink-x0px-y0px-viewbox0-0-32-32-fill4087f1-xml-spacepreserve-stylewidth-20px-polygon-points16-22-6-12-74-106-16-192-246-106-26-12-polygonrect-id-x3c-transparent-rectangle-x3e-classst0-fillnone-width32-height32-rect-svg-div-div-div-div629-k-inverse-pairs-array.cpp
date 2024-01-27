class Solution {
public:
    int kInversePairs(int n, int k) {
           vector<int>dp(k+1,0);
    vector<int>dp2(k+1,0); 
 
    dp[0]=1; dp2[0]=1;
    
    for(int i=1;i<=n;i++){
    long long ans=0;
    for(int j=0;j<=k;j++){
    ans+=dp[j];
    if(j>=i){
    ans-=dp[j-i];
    }
        dp2[j]=ans%1000000007;
        }
        swap(dp2,dp);
        }
      return dp[k]%1000000007;
    }
};