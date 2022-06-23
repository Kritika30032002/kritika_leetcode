class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
           vector<int>ans;
    int r=matrix.size();
    int c=matrix[0].size();
    int startRow=0;
    int endRow=r-1;
    int startCol=0;
    int endCol=c-1;

    while(startCol<=endCol && startRow<=endRow){
        //start Row
        for(int col=startCol;col<=endCol;col++){
            ans.push_back(matrix[startRow][col]);
        }
        
		//end column
        for(int row=startRow+1;row<=endRow;row++){
            ans.push_back(matrix[row][endCol]);
        }
        
		//end Row
        for(int col=endCol-1; col>=startCol;col--){
            if(startRow==endRow){
                break;
            }    
            ans.push_back(matrix[endRow][col]);
        }
       
	    //start Column
        for(int row=endRow-1;row>=startRow+1;row--){
            if(startCol==endCol){
                break;
            }
            ans.push_back(matrix[row][startCol]);
        }

        startRow++;
        endRow--;
        startCol++;
        endCol--;
    }
    
    return ans;
    }
};