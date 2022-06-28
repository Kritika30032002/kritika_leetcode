class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxi=0;
        for(int i=0;i<=heights.size();i++){
            while(!s.empty() && (i==heights.size() || heights[s.top()]>heights[i])){
                int h=heights[s.top()],width;
                s.pop();
                if(s.empty()) width=i;
                else width=i-s.top()-1;
                maxi=max(maxi,h*width);
                cout<<width<<" ";
            }
            s.push(i);
        }
        return maxi;
    }
};