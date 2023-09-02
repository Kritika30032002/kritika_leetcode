class Solution {
public:
    unordered_set<string> st;
    int n;
    int t[51];
    
    int solve(string &s, int idx){
        if(idx>=n)
            return 0;
        
        if(t[idx] != -1)
            return t[idx];
        
        string currStr="";
        int minExtra=n;
        
        for(int i=idx;i<s.size();i++){
            
            currStr.push_back(s[i]);
            
            int currExtra = (st.find(currStr) == st.end()) ? currStr.length() : 0;
            int nextExtra = solve(s,i+1);
            int totalExtra = currExtra + nextExtra;
            
            minExtra = min(minExtra,totalExtra);
        }
        
        return t[idx] = minExtra;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        n=s.length();
        
        memset(t,-1,sizeof(t));
        
        for(string &word : dictionary)
            st.insert(word);
        
        return solve(s,0);
    }
};