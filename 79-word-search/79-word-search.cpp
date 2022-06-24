class Solution {
public:

bool solve(int i,int j,int n,int m,vector<vector<char>>&board,string &word,int k)
{
    if(k==word.size())return true;
    if(i<0 or j<0 or i==n or j==m or board[i][j]!=word[k])
    {
        return false;
    }
    char ch=board[i][j];
    board[i][j]='#'; // adding the hash to mark is visited
    bool op1=solve(i+1,j,n,m,board,word,k+1);
    bool op2=solve(i,j-1,n,m,board,word,k+1);
    bool op3=solve(i,j+1,n,m,board,word,k+1);
    bool op4=solve(i-1,j,n,m,board,word,k+1);
    board[i][j]=ch;
    return op1 or op2 or op3 or op4;
    
}
bool exist(vector<vector<char>>& board, string word) 
{
      int n=board.size();
      int m=board[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(solve(i,j,n,m,board,word,0))
            {
                return true;
            }
        }
    }
    return  false;
    
}
};