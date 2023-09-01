class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        
        if(n==0)
            return ans;
        
        ans[0]=0;
        
        for(int i=1;i<=n;i++){
            ans[i]=__builtin_popcount(i);
        }
        return ans;
    }
};