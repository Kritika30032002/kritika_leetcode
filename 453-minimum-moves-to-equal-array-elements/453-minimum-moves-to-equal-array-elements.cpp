class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m=INT_MAX;
        for(int n:nums)
            m=min(n,m);
        int ans =0;
        for(int n:nums)
            ans+=n-m;
        return ans;
    }
};