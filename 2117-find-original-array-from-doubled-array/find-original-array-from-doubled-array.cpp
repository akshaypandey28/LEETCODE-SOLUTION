class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 != 0) return {}; //if the array size is odd

        vector<int> ans;
        sort(changed.begin(), changed.end());
        unordered_map<int, int> m; // Use int to count occurrences

        for (int num : changed)    m[num]++;
        

        for (int num : changed) {
            if (m[num] == 0) continue; // Skip , if the number is already used

            if (m[num * 2] > 0) {
                ans.push_back(num);
                m[num]--; // Decrease the count of the current number
                m[num * 2]--; // Decrease the count of the double
            } 
            else  return {}; // If no valid double exists, return an empty vector
            
        }

        return ans;
    }
};
