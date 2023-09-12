class Solution {
public:
    int minDeletion(vector<int>& nums) {
         int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] == nums[i + 1] and (i - ans) % 2 == 0) 
                ans++;
        
        return ans + (nums.size() - ans) % 2;
    }
};

// every time we find a duplicate we will increment ans by 1.

// thus to check the second condition we will subtract the ans value from the index as we are shifting the element to the left.

// for the last edge case we will check the remaining size after removing ans element from the vector if the result is odd we have to remove 1 more element else just return the ans.
    
    