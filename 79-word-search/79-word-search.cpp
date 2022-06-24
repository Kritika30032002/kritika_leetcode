class Solution {
public:
   bool solve(vector<vector<char>>& b,string w,int i,int j,int k){
        if(w[k] == '\0'){
            return true;
        }
        //checking outside
        if(i > b.size()-1 || j > b[0].size()-1) return false;
        
        bool up,right,down,left;
        
        if(b[i][j] == w[k]){
        //check up
            b[i][j] -= 60;
            up = solve(b,w,i-1,j,k+1);
            b[i][j] += 60;
        //check right
            b[i][j] -= 60;
           right = solve(b,w,i,j+1,k+1);
            b[i][j] += 60;
        //check left
            b[i][j] -= 60;
           left =  solve(b,w,i,j-1,k+1);
            b[i][j] += 60;
        //check down
            b[i][j] -= 60;
           down =  solve(b,w,i+1,j,k+1);
            b[i][j] += 60;
        }else{
            return false;
        }
        return (up || right || left || down);
    }
    
    bool exist(vector<vector<char>>& b, string w) {
        for(int i = 0;i<b.size();i++){
            for(int j =0;j<b[0].size();j++){
                if(b[i][j] == w[0]){
                   if(solve(b,w,i,j,0)) return true;
                }
            }
        }
        return false; 
    }
};