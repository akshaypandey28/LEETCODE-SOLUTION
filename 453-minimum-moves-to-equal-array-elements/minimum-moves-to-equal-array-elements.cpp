class Solution {
public:
    int minMoves(vector<int>& nums) {
        //We have to increment n-1 elements by 1 to make them equal.
        //This is equal to decrementing only 1 element by 1.
        //Take the minimum number from the array and then substarct that minimum number from all the elements in the array, the final answer is the sum of the difference between the minimum number and the integer values in the given array.

        int count=0;
        int mini=INT_MAX;
        for(int ele:nums) mini=min(mini,ele);
        for(int ele:nums) count+=ele-mini;
        return count;
    }
};