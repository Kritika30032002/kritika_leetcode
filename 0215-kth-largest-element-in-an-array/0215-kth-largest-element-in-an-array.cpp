class Solution {
public:
    
    //Hoare's partition
    int partition(vector<int>& nums,int left,int right){
        int pivot = nums[left];
        int l     = left+1;
        int r     = right;
        
        while(l<=r){
            if(nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++],nums[r--]);
            
            if(nums[l] >= pivot) 
                ++l;
            
            if(nums[r] <= pivot) 
                --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        //partition rule: >=pivot   pivot   <=pivot
        int left=0, right=nums.size()-1, idx=0;
        
        while(true) {
            
            idx = partition(nums,left,right);
            
            if(idx == k-1) //kth element
                break;
            else if(idx < k-1)
                left = idx+1;
            else
                right = idx-1;
        }
        
        return nums[idx];
    }
};
