class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = n + m; 
        while(n > 0) {
            if(m > 0) {
                if(nums1[m - 1] > nums2[n - 1]){
                    nums1[--k] = nums1[--m];
                } else {
                    nums1[--k] = nums2[--n];
                }
            } else {
                nums1[--k] = nums2[--n];
            }
        }
        return;
    }
};
