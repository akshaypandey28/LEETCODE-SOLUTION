class Solution {
public:
//using binary search T.C=> O(m*logn)
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int ans=0;
        for(int i=0; i<m; i++){
            int l=i,r=n-1;
            int best_j=-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(nums2[mid]>=nums1[i]){
                    best_j=mid;
                    l=mid+1; // Try to find a larger j
                }
                else r=mid-1;
            }
            if(best_j!=-1) ans=max(ans,best_j-i);
        }
        return ans;
    }
};