class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==val) count++;
        }
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]==val and nums[j]!=val){
                swap(nums[i],nums[j]);
                j--;
                i++;
            }
            if(nums[j]==val) j--;
            if(nums[i]!=val) i++;
        }
        return nums.size()-count;
    }
};