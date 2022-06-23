class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>> data;
        
        for(int i = 0;i<n-3;i++){
            //Important Constraint
            if(i>0 and nums[i] == nums[i-1])    continue;
            for(int j = i+1;j<n-2;j++){
                long long int required = target*1LL - nums[i] - nums[j];
                //Important Constraint
                if(j>i+1 and (nums[j] == nums[j-1]))    continue;
                int l = j+1;
                int r = n-1;
                
                while(l<r){
                    if(nums[l]+nums[r] == required){
                        data.insert({nums[i], nums[j], nums[l], nums[r]});
                        int temp = nums[l];
                        l++;
                        r--;
                    }
                    else if (nums[l]+nums[r] > required)
                        r--;
                    else l++;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto x:data){
            ans.push_back(x);
        }
        return ans;
    }
};