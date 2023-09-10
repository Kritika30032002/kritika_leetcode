//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
   
   int maxMeetings(int start[], int end[], int n) {
      vector<pair<int,int>>x;
    for(int i=0;i<n;i++)
       x.push_back({end[i],start[i]});
    
    sort(x.begin(),x.end());
    int c=1;
    int limit=x[0].first;
    for(int i=1;i<x.size();i++)
    {
        if(x[i].second>limit){ 
          c++;
          limit=x[i].first;
          }
    }
    return c;
   }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends