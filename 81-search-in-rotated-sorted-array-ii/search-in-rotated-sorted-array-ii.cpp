class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //i have to just find the sorted array in SRA
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target) return true;
            

            //Edge case:
            if (nums[l] == nums[mid] and nums[mid] == nums[h]) {
                l = l + 1;
                h = h - 1;
                continue;
            }
            //for right sorted array
            if(nums[mid]<=nums[h]){
                if(nums[mid] < target and target<=nums[h]) l=mid+1;
                else h=mid-1;
            }

            else {   //(nums[l]<=nums[mid]) left part is sorted 
                if(nums[l]<=target and target<nums[mid]) h=mid-1;
                else l=mid+1;
            }
        }
        return false;
    }
};