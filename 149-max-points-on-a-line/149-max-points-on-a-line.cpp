class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n= points.size();
        if(n<=2) return n;
        int res =2;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int total = 2;
                
                for(int k=0; k<n; k++){
                    if(i!=k and j!=k){
                        if((points[j][1]-points[i][1])* (points[i][0]-points[k][0])==                              (points[i][1]-points[k][1])* (points[j][0]-points[i][0])) total++;
                    }
                }
                res = max(total,res);
            }
        }
        return res;
    }
};