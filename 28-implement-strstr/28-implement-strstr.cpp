class Solution {
public:
    
    int strStr(string haystack, string needle) {
       if(needle.length()==0){
           return 0;
       }
        int i,j;
        
        for( i=0;i<haystack.length();i++){
            for(j=0;j<needle.length() && (i+j)<haystack.length();j++){
                if(haystack[i+j]==needle[j]){
                    continue;
                }
                else{
                    break;
                }
            }
            if(j==needle.length()){
                return i;
            }
        }
        return -1;
    }
};