class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int sp = 0;
        int tp = 0;
        string s1 = "";
        string t1 = "";
        while(sp < S.size()) {
            if(S[sp] == '#' && s1.size() == 0) {
                sp++;
            }
            else if(S[sp] == '#') {
                s1.pop_back();
                sp++;
            }
            else {
                s1.push_back(S[sp]);
                sp++;
            }
        }
        
        while(tp < T.size()) {
            if(T[tp] == '#' && t1.size() == 0) {
                tp++;
            }
            else if(T[tp] == '#') {
                t1.pop_back();
                tp++;
            }
            else {
                t1.push_back(T[tp]);
                tp++;
            }
        }
        return s1 == t1;       
    }
};