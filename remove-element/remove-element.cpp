class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      
       int j=nums.size()-1;
        
        for(int i=0;i<=j;i++){
            if(nums[i]==val){
                 while(nums[j]==val && j!=i && j>0 )
                      j--;
              swap(nums[i],nums[j--]);
        }
        }
        return j+1;                                                                                                                                                                                                                                 
    }
};