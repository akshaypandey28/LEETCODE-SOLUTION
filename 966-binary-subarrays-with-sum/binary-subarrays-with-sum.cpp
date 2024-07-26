class Solution {
public:
    int f(vector<int> nums,int goal){
        if(goal<0) return 0;
        int l=0,r=0;
        int sum=0;
        int count=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //subarray with sum<=goal
        return f(nums,goal) - f(nums,goal-1);
    }
};

/* 
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;  // zero sum always exist

        for (int num : nums) {
            sum += num;
            if (prefixSumCount.find(sum - goal) != prefixSumCount.end()) {
                ans += prefixSumCount[sum - goal];
            }
            prefixSumCount[sum]++;
        }
        
        return ans;
    }
};
 */