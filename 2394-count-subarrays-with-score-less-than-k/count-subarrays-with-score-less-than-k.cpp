class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count=0,sum=0;
        int r=0,l=0;

        while(r<nums.size()){
            sum+=nums[r];
            while(sum*(r-l+1) >=k){
                sum-=nums[l];
                l++;
            }

            count+=r-l+1; //count the no. of subarray

            r++;
        }
        return count;
    }
};