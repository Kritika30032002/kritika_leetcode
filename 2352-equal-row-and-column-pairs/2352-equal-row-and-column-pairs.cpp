//BRUTE FORCE SOLUTION O(n3)

// class Solution {
// public:
//     int equalPairs(vector<vector<int>>& grid) {
//         int n=grid.size();
        
//         int count=0;
        
//         for(int r=0;r<n;r++){    
//             for(int c=0;c<n;c++){
//                 bool isEqual=true;
//                 for(int i=0;i<n;i++){
//                     if(grid[r][i]!=grid[i][c]){
//                         isEqual=false;
//                         break;
//                     }                  
//                 }
//                 if(isEqual)
//                     count++;
//             }
//         }
//         return count;
//     }
// };


//OPTIMIZED SOLUTION - O(N2)
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        
        int count=0;
        
        map<vector<int>,int> mp;
        
        for(int r=0;r<n;r++){    
              mp[grid[r]]++;                
        }
        
        for(int c=0;c<n;c++){
            vector<int> temp;
           for(int r=0;r<n;r++){    
              temp.push_back(grid[r][c]);                
           }
            count+=mp[temp];
        }
        
        return count;
    }
};

