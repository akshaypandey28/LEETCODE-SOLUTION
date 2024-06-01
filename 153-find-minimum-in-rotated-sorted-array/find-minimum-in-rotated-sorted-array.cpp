class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        if(nums.size()==1) return nums[0];
        if(nums[0]<nums[h]) return nums[0];
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]>nums[mid+1]) return nums[mid+1];
            if(nums[mid]<nums[mid-1]) return nums[mid];
            if(nums[mid]>nums[l]) l=mid+1;
            else h=mid-1;
        }
        return -1;
    }
};