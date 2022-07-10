class Solution {
public:
    bool isPalindrome(int x) {
       
       string rev = to_string(x);  //covert number to string
        reverse(rev.begin(), rev.end());   //reverse the number
        return to_string(x) == rev;    //compare both
    }
};