class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> indegree(n,false);
        
        //build the indegree vector
        for(auto &edge: edges){
            int u=edge[0];
            int v=edge[1];
            
            indegree[v]=true;
        }
        
        vector<int> ans;
        
        //store nodes with indegree=0 and return
        for(int i=0;i<n;i++){
            if(indegree[i]==false)
                ans.push_back(i);
        }
        return ans;
    }
};


// https://www.youtube.com/watch?v=7wGJ1nevpnc