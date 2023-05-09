class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxS=INT_MIN;

        for(auto s:nums){
            sum+=s;
            maxS=max(maxS,sum);
            
            // If sum < 0: discard the sum calculated
            if(sum<0){
                sum=0;
            }
        }
        return maxS;
    }
};