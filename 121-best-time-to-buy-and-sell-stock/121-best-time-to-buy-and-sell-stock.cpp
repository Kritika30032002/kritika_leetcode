class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cp=INT_MAX,profit=0;
       int n=prices.size();
            for(int i=0;i<n;i++){
                cp=min(cp,prices[i]);
                profit=max(profit,prices[i]-cp);
            }
        return profit;
    }
};