class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0){ //if 0 points then 0 arrows 
            return 0;
        }
 
         // sort to cover more balloons
        sort(points.begin(),points.end());

        //at least one arrow will be used if size>=1
        int arrows=1;

        //initialise 'last' with last points of first balloon
        int last=points[0][1];

  for(int i=1;i<points.size();i++){
    if(points[i][0]>last){//if 1st point of balloon > last of another point  
                last=points[i][1];//then and 'last' has to be reinitialised
                arrows++; //then another arrow will be need
            }
    else{  //if 1st point of balloon < last of another point
             last=min(last,points[i][1]); //then last= min of both last points 
            }
        }
        return arrows; //return the number of arrows
    }
};

//Time Complexity => O(NlogN)
//Space Complexity => O(1)