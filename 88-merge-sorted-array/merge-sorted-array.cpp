class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.size()==0) return ;
        int i=0,j=0;
        while(i<m ){
            if(nums1[i]>nums2[0]){
                swap(nums1[i],nums2[0]);
                sort(nums2.begin(),nums2.end());
            }
            i++;
        }
        while(j<n and i<nums1.size()){
            nums1[i]=nums2[j];
            j++;
            i++;
        }
        return ;
    }
};