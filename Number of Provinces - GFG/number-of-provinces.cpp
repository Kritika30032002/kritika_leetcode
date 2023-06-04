//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
   void dfs(int src,vector<bool>&visited,vector<vector<int>>adj)
   {
        visited[src]=true ;
           for(int i=0;i<adj[src].size();i++)
           {
               if(i!=src && adj[src][i]==1 && visited[i]==false)
               {
                   dfs(i,visited,adj);
               }
            }
   }
    int numProvinces(vector<vector<int>> adj, int V) 
    {
        vector<bool>visited(V,false);
        int count=0;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                count++ ;
                dfs(i,visited,adj);
            }
        }
        
        return count ;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends