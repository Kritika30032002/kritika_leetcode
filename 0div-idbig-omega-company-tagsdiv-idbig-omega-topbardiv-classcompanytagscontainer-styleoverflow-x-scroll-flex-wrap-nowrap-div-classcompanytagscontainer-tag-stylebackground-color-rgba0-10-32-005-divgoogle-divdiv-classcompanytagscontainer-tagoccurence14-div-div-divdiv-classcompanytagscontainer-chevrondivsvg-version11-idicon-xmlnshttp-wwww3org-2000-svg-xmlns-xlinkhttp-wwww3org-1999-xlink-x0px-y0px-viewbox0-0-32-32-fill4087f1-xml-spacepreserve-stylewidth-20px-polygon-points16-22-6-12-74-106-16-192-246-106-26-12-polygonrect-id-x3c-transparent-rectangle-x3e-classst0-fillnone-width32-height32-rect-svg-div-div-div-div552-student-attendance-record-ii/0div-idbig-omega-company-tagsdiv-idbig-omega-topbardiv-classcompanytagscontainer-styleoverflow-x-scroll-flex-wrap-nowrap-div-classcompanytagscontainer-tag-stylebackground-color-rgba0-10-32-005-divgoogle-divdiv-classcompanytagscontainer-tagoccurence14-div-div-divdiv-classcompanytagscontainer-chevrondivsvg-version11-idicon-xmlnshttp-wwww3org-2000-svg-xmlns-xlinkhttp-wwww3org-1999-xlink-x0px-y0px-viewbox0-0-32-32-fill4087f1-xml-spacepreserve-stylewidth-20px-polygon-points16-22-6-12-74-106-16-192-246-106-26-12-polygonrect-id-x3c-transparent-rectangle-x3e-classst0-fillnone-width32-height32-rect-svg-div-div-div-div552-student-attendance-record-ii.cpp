class Solution {
public:
    int M = 1e9+7;

    int checkRecord(int n) {
        int t[100001][2][3]; 

        //t[i][A][L] = # award possibilities till ith day , having j absence, k consecutive lates

        //Base Case - 0 number of days. So, t[0][A][L], we return 1
        for (int A = 0; A <= 1; ++A) {
            for (int L = 0; L <= 2; ++L) {
                t[0][A][L] = 1;
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int A = 0; A <= 1; A++) {
                for(int L = 0; L <= 2; L++) {

                    long long result = t[i-1][A][0];         // P ---> solve(n-1, absent, 0) % M;
                    result += (L < 2 ? t[i-1][A][L+1] : 0);  // L ---> solve(n-1, absent, consecutive_late+1) % M;
                    result += (A == 0 ? t[i-1][A+1][0]: 0);  // A ---> solve(n-1, absent+1, 0) % M;
                    
                    t[i][A][L] = result % M;
                }
            }
        }

        return t[n][0][0]; //---> return solve(n, 0, 0);

    }
};