class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        //Transpose of The given matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++)
                swap(matrix[i][j],matrix[j][i]);
        }
        
        //reverse the each row elements to get rotate image
        for(int i=0;i<n;i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }
};