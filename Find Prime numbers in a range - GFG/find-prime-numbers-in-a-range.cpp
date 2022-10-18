//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
        // code here
       
         vector<bool>ans(N+1,true);
        ans[0]=false;
        ans[1]=false;
        vector<int>res;
        for(int i=2;i<=N;i++)
        {
            for(int j=2*i;j<=N;j+=i)
            {
                ans[j]=false;
            }
        }
        for(int i=M;i<=N;i++)
        {
            if(ans[i]==true)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends