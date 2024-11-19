//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(begin(nums), end(nums)); //nlogn

        long long result = 0;

        for(int i = 0; i < n; i++) { //O(n * logn)
             //o(n)
            int idx = lower_bound(begin(nums) + i + 1, end(nums), lower-nums[i]) - begin(nums); 
            //Gives the first element NOT LESS than (lower - nums[i]) log(n)
            int x   = idx - 1 - i; //count the no. of element which is less than lower-nums[i]
            //between i+1 to idx


            idx = upper_bound(begin(nums) + i + 1, end(nums), upper-nums[i]) - begin(nums); //Gives
            //the first element GREATER than (upper - nums[i]) log(n)

            int y = idx - 1 - i;

            result += (y-x);
        }

        return result;
    }
};