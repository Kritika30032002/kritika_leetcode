class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int result = -1;
   
        int arr[2001] = {0};

        for (int num : nums) {

            if (arr[-num + 1000] == 1)
                result = max(result, abs(num));

            // Mark the current number as seen
            arr[num + 1000] = 1;
        }

        return result;
    }
};