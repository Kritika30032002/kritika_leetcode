class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water=0;
       int  left =0, right=height.size()-1;
        
        while(left<right){
           int area = (right-left)*min(height[left],height[right]);
            max_water=max(max_water,area);
            
            if(height[left]<height[right])
                 left++;
            else
                 right--;
        }
        
        return max_water;
    }
};