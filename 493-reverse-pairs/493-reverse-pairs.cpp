class Solution {
public:
    int count=0;
    int reversePairs(vector<int>& nums) {
        int n=nums.size()-1;
        divide(nums,0,n);
        
    return count;
    }
    
    void divide(vector<int>&nums, int start, int end){
        if(start>=end)
            return;
        
        int mid=(start+end)/2;  //logn
        divide(nums,start, mid);
        divide(nums,mid+1, end);   
        merge(nums, start, mid, end); //n
        
        //tc=O(NLOGN)
    }
    
    void merge(vector<int>&nums, int start, int mid, int end){
        
        int s1=start, s2=mid+1;
        
        int j=mid+1;
        for(int i=start;i<=mid;i++){
            while(j<=end && nums[i] > 2*(long long)nums[j]){
                j++;
            }
            count+=(j-(mid+1));
            
        }
        
        vector<int>temp;
        
        while(s1<=mid && s2<=end){
            
            if(nums[s1]< nums[s2]){
                temp.push_back(nums[s1]);
                s1++;
            }
            else{
                temp.push_back(nums[s2]);
                s2++;
            }
            
        }
        
        while(s1<=mid){
            temp.push_back(nums[s1]);
            s1++;
        }
        
        while(s2<=end){
            temp.push_back(nums[s2]);
            s2++;
        }
        
        int i=0, n=temp.size();
        while(i<n){
            nums[start]=temp[i];
            i++;
            start++;
        }
    }
};