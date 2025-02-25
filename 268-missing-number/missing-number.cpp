class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            ans=ans^i;
            ans=ans^nums[i];
        }
        if(ans==0) return nums.size();
        return ans^nums.size();
    }
};

/* 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<nums.size(); i++) sum+=nums[i];
        int total=(n*(n+1))/2;
        return total-sum;
    }
};
 */