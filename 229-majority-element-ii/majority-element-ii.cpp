class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans; //this can be max of size 2
        int ele1,ele2;
        int cnt1=0,cnt2=0;
        for(int i=0; i<nums.size(); i++){
            if(cnt1==0 and ele2!=nums[i]){
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0 and ele1!=nums[i]){
                cnt2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i=0; i<nums.size(); i++){
            if(ele1==nums[i]) cnt1++;
            if(ele2==nums[i]) cnt2++;
        }
        if(cnt1 > nums.size()/3) ans.push_back(ele1);
        if(cnt2 > nums.size()/3 and ele2!=ele1) ans.push_back(ele2);

        return ans;
    }
};