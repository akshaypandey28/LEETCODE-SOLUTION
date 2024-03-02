class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find greater than a[i] so that i can get close
        //as soon i get greater than a[i] remaining elements gets places in sorted order
        //find the particular index from last of the array if at any moment a[i]<a[i]+1 this is our breakpoints that is dip in the cirve
        int idx=-1;
        int n=nums.size();
        // Step 1: Find the break point: 
        //by traversing from the last of the array if any elements is found dip in the increasing curve like next greater element
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                idx=i; //this is the first element in the curve where the dip is found this has to be swapped with number which is just greater than nums[idx]
                break;
            }
        }
        if(idx==-1) {
            reverse(nums.begin(),nums.end());
            return ;
        }
        
        for(int i=n-1; i>idx; i--){
            if(nums[i]>nums[idx]) {
                swap(nums[i],nums[idx]);
                break;
            }
        }

        sort(nums.begin()+idx+1,nums.end());
        return ;
    }
};