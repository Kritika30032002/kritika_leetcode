
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod=1e9+7;
        int prefSum=0; int ans=0;
        int oddCnt=0; int evenCnt=1;
        
        for(int i=0;i<arr.size();i++){
            prefSum+=arr[i];
            
            if(prefSum%2==0){
                ans=(ans+oddCnt)%mod;
                evenCnt++;
            }
            else{
                ans=(ans+evenCnt)%mod;
                oddCnt++;
            }
        }
        return ans;
    }
};