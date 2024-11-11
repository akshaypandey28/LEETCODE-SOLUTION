class Solution {
public:
    int OR=0; //or of the whole array
    int ans=0;
    void f(vector<int> &nums,int x,int i,int n){
        if(i==n){
            if(x==OR) ans++;
            return ;
        }
        f(nums,x|nums[i],i+1,n);
        f(nums,x,i+1,n);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) OR|=nums[i];

        f(nums,0,0,nums.size()); //(0,0) => (or of the subset,index)
        return ans;

    }
};