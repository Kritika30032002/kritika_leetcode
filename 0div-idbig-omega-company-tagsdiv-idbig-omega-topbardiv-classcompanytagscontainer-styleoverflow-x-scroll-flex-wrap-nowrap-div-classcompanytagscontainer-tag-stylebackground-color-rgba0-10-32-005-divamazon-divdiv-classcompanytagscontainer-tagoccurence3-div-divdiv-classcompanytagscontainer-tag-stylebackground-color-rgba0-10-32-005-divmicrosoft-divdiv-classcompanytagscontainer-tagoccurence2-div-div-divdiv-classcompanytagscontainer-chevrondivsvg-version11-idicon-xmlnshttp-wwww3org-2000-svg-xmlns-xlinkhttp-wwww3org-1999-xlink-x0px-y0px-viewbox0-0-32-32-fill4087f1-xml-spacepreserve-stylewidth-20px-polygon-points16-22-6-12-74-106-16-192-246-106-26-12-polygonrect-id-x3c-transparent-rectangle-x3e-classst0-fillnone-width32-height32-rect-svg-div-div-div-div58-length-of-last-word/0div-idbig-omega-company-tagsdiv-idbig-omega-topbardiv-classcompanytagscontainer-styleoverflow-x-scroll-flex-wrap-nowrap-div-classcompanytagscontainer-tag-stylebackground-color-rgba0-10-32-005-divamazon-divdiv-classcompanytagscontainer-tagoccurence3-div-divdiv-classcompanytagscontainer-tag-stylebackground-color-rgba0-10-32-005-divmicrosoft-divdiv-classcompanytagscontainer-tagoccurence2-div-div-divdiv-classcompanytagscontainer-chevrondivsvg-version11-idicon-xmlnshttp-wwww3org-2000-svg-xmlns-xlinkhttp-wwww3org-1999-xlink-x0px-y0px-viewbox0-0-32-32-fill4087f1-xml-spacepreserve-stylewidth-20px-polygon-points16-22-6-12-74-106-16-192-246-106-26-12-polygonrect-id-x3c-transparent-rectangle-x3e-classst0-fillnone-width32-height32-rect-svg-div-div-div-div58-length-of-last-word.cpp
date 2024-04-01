class Solution {
public:
    int lengthOfLastWord(string s) {
         s.erase(s.find_last_not_of(' ') + 1); //Removes the trailing spaces
        
        // Find the last space character
        int lastSpace = s.find_last_of(' ');

        // Calculate the length of the last word
        return lastSpace == string::npos ? s.length() : s.length() - lastSpace - 1;
    }
};