class Solution {
    int Space_Optimize(vector<int> &days, vector<int> &cost){
    int ans = 0;

    queue<pair<int, int>> month;
    queue<pair<int, int>> week;

    for (int day: days){

        // Step 1 - remove the expired days from queue
        while(!month.empty() && month.front().first+30 <= day){
            month.pop();
        }

        while(!week.empty() && week.front().first+7 <= day){
            week.pop();
        }

        // Step 2- Add cost for current days
        month.push(make_pair(day, ans+cost[2]));
        week.push(make_pair(day, ans+cost[1]));

        // Step 3 - Store the ans
        ans = min(ans+cost[0], min(month.front().second, week.front().second));
    }

    return ans;
}
public:
    int mincostTickets(vector<int>& DAYS, vector<int>& cost) {
        
        return Space_Optimize(DAYS, cost);
    }
};