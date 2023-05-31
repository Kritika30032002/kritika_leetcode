class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum;
        for(int i=0;i<candies.size();i++)
            sum+=candies[i];
        
        long long low=1;
        long long high=sum/k;
        
        long long ans=0;
        
        while(low<=high){
            long long mid=(low+high)/2;
            
            long long totalKitniPilesBanaSaktaHuJismeMidCandiesHo=0;
            
            for(auto itr:candies){
                totalKitniPilesBanaSaktaHuJismeMidCandiesHo+=(itr/mid);
            }
            if(totalKitniPilesBanaSaktaHuJismeMidCandiesHo >= k){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};