class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
            int remainder=0;
        while(columnNumber){
            remainder=columnNumber % 26;
            if(remainder==0)
                remainder=26;
            char c= 64 + remainder;
            ans=c+ans;
            columnNumber=(columnNumber-remainder)/26;
        }
        return ans;
    }
};