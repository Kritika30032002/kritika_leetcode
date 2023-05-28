class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
     unordered_map<int,int> mp;
        
     int n=arr.size();   
        
    vector<int> ans;    

	for(int i=0;i<n;i++){
		mp[arr[i]]++;
	}

	for(auto num: mp){
		if(num.second>n/3)
		  ans.push_back(num.first);
	}

	return ans;
    }
};