class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int actual_idx=m+n-1; //for storing elements
        m--;
        n--;
        while(n>=0){
            if(m>=0 and nums1[m]>=nums2[n]){
                nums1[actual_idx]=nums1[m];
                m--;
            }
            else {
                nums1[actual_idx]=nums2[n];
                n--;
            }
            actual_idx--;
        }
        return ;
    }
};