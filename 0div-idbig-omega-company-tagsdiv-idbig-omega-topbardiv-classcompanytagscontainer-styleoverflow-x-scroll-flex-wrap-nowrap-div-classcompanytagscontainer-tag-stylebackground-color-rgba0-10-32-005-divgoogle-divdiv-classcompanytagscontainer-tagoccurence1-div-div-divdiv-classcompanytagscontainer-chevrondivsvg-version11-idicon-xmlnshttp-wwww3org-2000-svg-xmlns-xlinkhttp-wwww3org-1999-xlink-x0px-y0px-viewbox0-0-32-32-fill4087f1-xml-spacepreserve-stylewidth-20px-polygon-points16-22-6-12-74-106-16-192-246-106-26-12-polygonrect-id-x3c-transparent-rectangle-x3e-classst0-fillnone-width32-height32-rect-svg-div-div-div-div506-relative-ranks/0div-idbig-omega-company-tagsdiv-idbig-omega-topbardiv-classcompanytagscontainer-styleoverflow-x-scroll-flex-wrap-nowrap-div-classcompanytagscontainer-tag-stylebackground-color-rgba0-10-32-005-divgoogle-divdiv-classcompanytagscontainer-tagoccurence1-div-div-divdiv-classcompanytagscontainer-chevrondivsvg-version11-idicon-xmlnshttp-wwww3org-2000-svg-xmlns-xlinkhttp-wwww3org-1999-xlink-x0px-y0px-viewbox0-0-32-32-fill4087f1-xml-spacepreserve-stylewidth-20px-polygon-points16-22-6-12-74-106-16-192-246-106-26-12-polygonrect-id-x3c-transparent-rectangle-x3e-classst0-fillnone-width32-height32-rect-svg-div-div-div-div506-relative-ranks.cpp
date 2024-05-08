class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int,vector<int>> pq(begin(score),end(score));
        vector<string> ans(score.size());
        int place = 0;
        while(!pq.empty()){
            int ele = pq.top();
            for(int i = 0;i<score.size();i++){
                if(score[i] == ele){
                    place++;
                    if(place == 1) ans[i] = "Gold Medal";
                    else if(place == 2) ans[i] = "Silver Medal";
                    else if(place == 3) ans[i] = "Bronze Medal";
                    else ans[i] = to_string(place);
                    pq.pop();
                    break;
                }
            }
        }
        return ans;
    }
};