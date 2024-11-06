class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<pair<int,int>> segment; 
        int maxi=nums[0];
        int mini=nums[0];
        int bits=__builtin_popcount(maxi);
        for(int i=1; i<nums.size(); i++){
            if(__builtin_popcount(nums[i]) == bits ) {
                maxi=max(maxi,nums[i]);
                mini=min(mini,nums[i]);
            }
            else{
                segment.push_back({maxi,mini});
                bits=__builtin_popcount(nums[i]);
                maxi=nums[i];
                mini=nums[i];
            }
        }
        segment.push_back({maxi,mini});
        for(int i=1; i<segment.size(); i++){
            if(segment[i-1].first > segment[i].second) return false;
        }
        return true;
    }
};