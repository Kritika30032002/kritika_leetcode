class Solution {
    long long solve(vector<vector<int>>& q,int i,vector<long long> &dp){
        if(i>=q.size())
             return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        long long taken=q[i][0]+ solve(q,i+q[i][1]+1,dp);
        long long not_taken=solve(q,i+1,dp);
        
        return dp[i]=max(taken,not_taken);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n+1,-1);
        return solve(questions,0,dp);
    }
};

// https://www.youtube.com/watch?v=NcC8lo7nLCE