class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        for(int i=0; i<n; i++) {

            if(nums[i]>0) s.insert(nums[i]);
        }
        for(int i=1; i<=maxi; i++){
            if(s.find(i)==s.end()) return i;
        }
        if(maxi<0) return 1;
        return maxi+1;
    }
};