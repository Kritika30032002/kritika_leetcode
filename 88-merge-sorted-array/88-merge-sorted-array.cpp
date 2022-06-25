class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int count=n;
int i=0;
for(i=0; count>0; i++ ){
        nums1[m]=nums2[i];
        m++;
        count--;
}
sort(nums1.begin(),nums1.end());
    }
};