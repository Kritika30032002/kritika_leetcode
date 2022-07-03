class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> mp;
        
        vector<vector<string>> ans;
        
        string temp;
        
        for(auto x:strs)
        {
            temp=x; // preserving the original string
            
            sort(x.begin(),x.end()); // sorting each string because all anagrams after sorting will result in same string
            
            mp[x].push_back(temp); //grouping each string according to sorted string
        }
        
        for(auto x:mp)
            ans.push_back(x.second); // pushing the answer in vector to return 
        
        return ans;
    }
};