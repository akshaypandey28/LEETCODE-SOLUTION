/* 
We traverse through unique numbers in frequency, computing possible triplets dynamically.

Variables:

prev: Tracks the count of numbers we have seen so far.
nxt: Tracks how many numbers remain after processing the current number.
Mathematical Breakdown:

For a number X appearing freq times:
prev = Count of numbers before X
nxt = Count of numbers after X
The number of triplets that can be formed is:
prev
×
freq
×
nxt
prev×freq×nxt
This ensures:
prev picks one value before X
freq picks one value from X
nxt picks one value after X
 */
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int count = 0, prev = 0, nxt = nums.size();
        unordered_map<int, int> frequency;

        // Step 1: Count frequency of each number
        for (int n : nums) 
            frequency[n]++;
        
        // Step 2: Iterate over unique numbers to count valid triplets
        for (auto[n, freq] : frequency){
            nxt -= freq;                // Remaining elements after picking `n`
            count += prev * freq * nxt;  // Calculate triplets
            prev += freq;                // Accumulate seen elements
        }
        return count;
    }
};
