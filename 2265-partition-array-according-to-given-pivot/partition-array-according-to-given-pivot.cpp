class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> ans(n,pivot);
        int l=0,r=n-1;
        int i=0,j=n-1; //it is for placing the elements into ans from left and right side
        while(l<n and r>=0){
            if(nums[l]<pivot){
                ans[i]=nums[l];
                i++;
            }
            if(nums[r]>pivot){
                ans[j]=nums[r];
                j--;
            }
            l++;
            r--;
        }
        return ans;
    }
};