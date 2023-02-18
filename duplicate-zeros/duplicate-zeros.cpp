class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector <int> ans;
        
        for(int i=0;i<arr.size();i++){
            if(ans.size()!=arr.size()){
                if(arr[i]!=0){
                    ans.push_back(arr[i]);
                }
                else{
                    ans.push_back(0);
                     if(ans.size()!=arr.size()){
                         ans.push_back(0);
                     }  
                }
            }
        }
        
        arr=ans;
    }
};