class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0,sum=0;
        int l=0,r=0;
        unordered_set<int> s;
        while(r<nums.size()){

            while(s.empty()!=1 and s.find(nums[r])!=s.end()){
                sum-=nums[l];
                s.erase(nums[l]);
                l++;

            }

            sum+=nums[r];
            s.insert(nums[r]);
            //if(s.size()==k) ans=max(ans,sum);
            if(s.size()>k){
                sum-=nums[l];
                s.erase(nums[l]);
                l++;
            }
            if(s.size()==k) ans=max(ans,sum);
            
            
            r++;
        }
        return ans;
    }
};