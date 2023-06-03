
//BFS --- O(N)
class Solution {
public:
     int max_time=INT_MIN;
    
void BFS(map<int,vector<int>> &adj, vector<int> &informTime ,int headID){
        
     queue<pair<int,int>> que;
         
     que.push({headID,0});
         
     while(!que.empty()){
         
         pair<int,int> temp=que.front();
         
         int curr_employee = temp.first;
         int curr_time = temp.second;
         
         max_time=max(curr_time,max_time);
         
         que.pop();
         
         
        for(auto &subordinate: adj[curr_employee]){
            que.push({subordinate, curr_time+informTime[curr_employee]});
        }
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
        
        BFS(adj,informTime,headID);
        return max_time;
    }
};








// DFS----- O(N)
// class Solution {
// public:
//     int max_time=INT_MIN;
    
//     void DFS(map<int,vector<int>> &adj, vector<int> &informTime ,int curr_employee, int curr_time){
        
//         max_time=max(curr_time,max_time);
        
//         for(auto &subordinate: adj[curr_employee]){
//          DFS(adj, informTime, subordinate, curr_time+informTime[curr_employee] );
//         }
//     }
    
//     int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
//         map<int,vector<int>> adj;
        
//         for(int i=0;i<manager.size();i++){
//             int child=i;
//             int currmanager=manager[i];
            
//             if(manager[i]!=-1)
//                  adj[manager[i]].push_back(child);
//         }
        
//         DFS(adj,informTime,headID,0);
//         return max_time;
//     }
// };