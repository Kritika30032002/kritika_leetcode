//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n; //Each person given one candy
        
        int i=1;
        while(i < n){
            
            if(ratings[i] == ratings[i-1]) {
                i++;
                continue;
            }
            
            //For increasing slope
            int peak = 0;
            while(ratings[i] > ratings [i-1]){
                peak++;
                candy += peak;
                i++;
                if(i == n) return candy;
            }
            
            //For decreasing slope
            int dip = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                dip++;
                candy += dip;
                i++;
            }
            
            //Note that we added candies coming from left to Peak and comgin from right to Peak
            //But, we need to consider only max from both of them for the Peak.
            //So, remove the min candy from Peak.
            candy -= min(peak, dip);
        }
        
        return candy;
    }
};



// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//            int n = ratings.size();
//         vector<int> count(n, 1);

//         //First comparing with only left neighbour
//         for(int i = 1; i<n; i++) {
//             if(ratings[i] > ratings[i-1])
//                 count[i] = max(count[i], count[i-1]+1);
//         }
        
//         //Then comparing with only right neighbour
//         for(int i = n-2; i>=0; i--) {
//             if(ratings[i] > ratings[i+1])
//                 count[i] = max(count[i], count[i+1]+1);
//         }
        
        
//         // return accumulate(begin(count), end(count), 0);
        
//          int result = 0;
//         for (auto t: count) result += t;
//         return result;
//     }
// // };

 
       


// https://www.youtube.com/watch?v=YUT13Koh5Jg