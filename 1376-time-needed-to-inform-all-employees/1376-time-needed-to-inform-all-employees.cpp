class Solution {
public:
    int max_time=INT_MIN;
    
    void DFS(map<int,vector<int>> &adj, vector<int> &informTime ,int curr_employee, int curr_time){
        
        max_time=max(curr_time,max_time);
        
        for(auto &subordinate: adj[curr_employee]){
         DFS(adj, informTime, subordinate, curr_time+informTime[curr_employee] );
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        map<int,vector<int>> adj;
        
        for(int i=0;i<manager.size();i++){
            int child=i;
            int currmanager=manager[i];
            
            if(manager[i]!=-1)
                 adj[manager[i]].push_back(child);
        }
        
        DFS(adj,informTime,headID,0);
        return max_time;
    }
};