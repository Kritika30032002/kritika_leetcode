class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //go with greedy approach
        int n = (int) intervals.size();
        //sort intervals based on their start time
        sort(intervals.begin(),intervals.end());
        
        //storing the end time of the 1st task 
        int prev = intervals[0][1];
        int ans = 0;
        
        for(int i=1;i<n;i++){
            //if the end time of any interval exceeds the start time of the previous task, conflict occurs 
            if(prev > intervals[i][0]){
                ans++;
                prev = min(prev,intervals[i][1]);
            }
            //no conflict occurs
            else{
                prev = intervals[i][1];
            }
        }
        
        //return ans
        return ans;
    }
};