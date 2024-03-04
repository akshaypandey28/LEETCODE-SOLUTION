class Solution {
public:
    int search(vector<int>& nums, int target) {
        //i have to just identify the sorted part of the array
        int n=nums.size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=l + (h-l)/2;
            if(nums[mid]==target) return mid;
            if(nums[l]<=nums[mid]){ //left part is sorted 
                if(nums[l]<=target and target<nums[mid]) h=mid-1;
                else l=mid+1;
            }
            else{//right part is sorted
                if(nums[mid]<target and target<=nums[h]) l=mid+1;
                else h=mid-1;
            }
        }
        return -1;
    }
};