class Solution {
public:
//same as 930
    int f(vector<int> nums,int k){
        if(k<=0) return 0;
        int count=0;
        int l=0,r=0;
        unordered_map<int,int> m;
        while(r<nums.size()){
            m[nums[r]]++;
            while(m.size()>k){
                m[nums[l]]--;
                if(m[nums[l]]==0) m.erase(nums[l]);
                l++;
            }
            if(m.size()<=k) count+=r-l+1; //counts the number of subarray
            r++;
        }
        return count;

    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //(<=k - <k) ==k
        return f(nums,k) - f(nums,k-1);
    }
};