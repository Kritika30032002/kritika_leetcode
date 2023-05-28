// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//     int start=0;
//         int end=nums.size()-1;
//         sort(nums.begin(),nums.end());
//         int mid=end/2;
//         return nums[mid];
//     }
// };




//OPTIMIZED

class Solution {
public:
    int majorityElement(vector<int>& v) {
int cnt = 0; // count
    int el; // Element
        
        int n=v.size();

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] == el)
        cnt1++;
    }

    if (cnt1 > (n / 2))
      return el;
    return -1;
   }
};