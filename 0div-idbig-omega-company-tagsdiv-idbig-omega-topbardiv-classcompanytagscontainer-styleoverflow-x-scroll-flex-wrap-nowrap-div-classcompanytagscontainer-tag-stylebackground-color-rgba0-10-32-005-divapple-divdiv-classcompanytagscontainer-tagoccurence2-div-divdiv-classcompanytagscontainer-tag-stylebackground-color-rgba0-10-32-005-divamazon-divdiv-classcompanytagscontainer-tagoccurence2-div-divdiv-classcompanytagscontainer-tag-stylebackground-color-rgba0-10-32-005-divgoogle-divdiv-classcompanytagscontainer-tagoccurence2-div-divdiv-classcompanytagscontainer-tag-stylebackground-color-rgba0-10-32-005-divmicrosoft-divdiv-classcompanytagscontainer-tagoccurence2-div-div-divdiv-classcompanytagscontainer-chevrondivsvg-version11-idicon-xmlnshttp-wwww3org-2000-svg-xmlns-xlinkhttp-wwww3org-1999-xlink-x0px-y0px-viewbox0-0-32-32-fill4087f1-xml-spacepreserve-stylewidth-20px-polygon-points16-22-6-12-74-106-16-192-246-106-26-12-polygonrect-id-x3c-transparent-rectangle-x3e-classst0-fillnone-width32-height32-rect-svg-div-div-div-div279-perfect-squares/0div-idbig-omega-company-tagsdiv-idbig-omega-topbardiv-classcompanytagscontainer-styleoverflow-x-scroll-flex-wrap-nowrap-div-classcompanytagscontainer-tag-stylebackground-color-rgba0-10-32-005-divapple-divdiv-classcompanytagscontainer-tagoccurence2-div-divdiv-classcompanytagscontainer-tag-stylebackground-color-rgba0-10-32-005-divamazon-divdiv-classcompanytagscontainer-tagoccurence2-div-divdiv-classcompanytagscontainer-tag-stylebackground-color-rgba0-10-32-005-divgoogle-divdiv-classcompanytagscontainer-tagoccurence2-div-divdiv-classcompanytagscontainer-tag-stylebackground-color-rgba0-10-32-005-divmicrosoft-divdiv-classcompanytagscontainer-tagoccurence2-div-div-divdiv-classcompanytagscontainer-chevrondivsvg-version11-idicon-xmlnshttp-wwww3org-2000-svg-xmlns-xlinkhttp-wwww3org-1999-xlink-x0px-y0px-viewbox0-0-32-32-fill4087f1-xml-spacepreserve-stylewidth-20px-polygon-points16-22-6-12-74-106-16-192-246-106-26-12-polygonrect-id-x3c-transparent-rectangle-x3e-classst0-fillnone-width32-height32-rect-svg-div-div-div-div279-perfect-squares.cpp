class Solution {
public:
    int numSquares(int n) {
        vector<int> t(n+1, INT_MAX);
        //t[i] = min number of perfect squares to get i
        t[0] = 0;
        
        for(int i = 1; i<=n; i++) {
            
            // For each i, it must be the sum of some number (i - j*j) and 
            // a perfect square number (j*j).
            for(int j = 1; j*j<=i; j++) {
                int remain = i-j*j;
                
                t[i] = min(t[i], 1 + t[remain]);
            }
        }
        
        return t[n];
    }
};