class Solution {
    int solve(vector<int>& cuts,int l,int r){
        if(r-l<2)
             return 0;
        
        if(t[l][r] != -1)
            return t[l][r];
        
        int result=INT_MAX;
        
        for(int i=l+1;i<=r-1;i++){
            int cost=(cuts[r]-cuts[l])+solve(cuts,l,i)+solve(cuts,i,r);
            
            result=min(result,cost);
        }
        
        return t[l][r]=result;
    }
public:
    int t[103][103];
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        memset(t, -1, sizeof(t));
        
        return solve(cuts,0,cuts.size()-1);
    }
};