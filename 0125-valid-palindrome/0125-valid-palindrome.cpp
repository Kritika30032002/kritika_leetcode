class Solution {
public:
    bool valid(char ch){
        if ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            return true;
        }
        return false;
    }
    
char toLowers(char ch){
     if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
         return ch;
         }
      else{
           char temp =ch- 'A'+ 'a';
           return temp;
        }
}
    
    bool isPalindrome(string s) {
        string str;
   
   for(int i=0; i<s.length(); i++){
       if(valid(s[i])){
           str.push_back(s[i]);
       }
   }
   
   int st=0;
int e=str.length()-1;
     
   while(st<=e){
       
   if(toLowers(str[st])!=toLowers(str[e])){
     return 0;
   }
   else{
     st++;
     e--;
   }
 }
 return 1;
    }
};