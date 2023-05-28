#define ll long long int
class NumMatrix {
public:
    vector<vector<ll>> pref;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        pref = vector<vector<ll>>(n+1, vector<ll>(m+1, 0));
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+matrix[i-1][j-1];
            }
        }
    }
   
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        return pref[row2][col2]-pref[row2][col1-1]-pref[row1-1][col2]+pref[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */