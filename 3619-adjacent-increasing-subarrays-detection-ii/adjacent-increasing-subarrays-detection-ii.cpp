class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int> store;
        int count=0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]<nums[i+1]) count++;
            else{
                store.push_back(count+1);
                count=0;
            }
        }
        store.push_back(count+1);
        int ans=store[0]/2;
        for(int i=1; i<store.size(); i++){
            if(store[i-1]>store[i]){
                ans=max({ans,store[i],store[i-1]/2});
            }
            else if(store[i-1]==store[i]){
                ans=max(ans,store[i]);
            }
            else{
                ans=max({ans,store[i-1],store[i]/2});
            }
        }
        //if(ans==0) return 1;
        return ans;
    }
};