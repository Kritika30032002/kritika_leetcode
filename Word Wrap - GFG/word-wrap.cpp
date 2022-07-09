// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
          int n=nums.size();
     int dp[n+1];
     dp[n]=0;
     dp[n-1]=0;
     if(n==1){return 0;}
     
     for(int i=n-2;i>=0;i=i-1)
     {
         int curr=nums[i];
         dp[i]=dp[i+1]+(k-nums[i])*(k-nums[i]);
          
         int aja=1;
         while(aja<n-i)
         {   
             curr=curr+nums[i+aja]+1;
          
             if(curr<=k)
             {   if(i+aja==n-1){dp[i]=0;}
                 else{dp[i]=min(dp[i],(k-curr)*(k-curr)+dp[i+aja+1]);}
             }
             else{break;}
            aja=aja+1;
         }
     }
     return dp[0];
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends