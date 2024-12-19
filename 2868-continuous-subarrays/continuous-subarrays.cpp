//Approach-1 (Using Ordered Map)
//T.C : ~O(n) - Explained in the video why O(n) ?
//S.C : ~O(1) - Explained in the video why O(1) ?
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        map<int, int> mp;

        int i = 0;
        int j = 0;

        long long count = 0;

        while(j < n) {
            mp[nums[j]]++;
            
            while(abs(mp.rbegin()->first - mp.begin()->first) > 2) { //it means it is out of the bound 2
                //shrink window => move i index
                mp[nums[i]] -= 1;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            count += j-i+1; //it gives the number of subarray can be formed by including jth element
            j++;
        }

        return count;
    }
};