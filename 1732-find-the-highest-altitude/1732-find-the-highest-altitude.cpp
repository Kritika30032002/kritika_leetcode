class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max=0;
        
        int j=0;
        
        for(int i=0;i<gain.size();i++){
            
            j=j+gain[i];
            if(j>max) 
                max=j;
            
        }
        return max;
    }
};