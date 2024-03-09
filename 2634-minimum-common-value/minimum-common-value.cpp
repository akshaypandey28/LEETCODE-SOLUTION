class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for(int i=0; i<nums1.size(); i++) s.insert(nums1[i]);
        int ans=INT_MAX;
        for(int i=0; i<nums2.size(); i++){
            if(s.count(nums2[i])) ans=min(ans,nums2[i]);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};