class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n , 0); // Difference array with size n + 1
        
        // Step 1: Populate the difference array
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            
            if (direction == 1) { // Forward shift
                diff[start] += 1;
                if(end+1 < n) diff[end + 1] -= 1;
            } 
            else { // Backward shift
                diff[start] -= 1;
                if(end+1 < n) diff[end + 1] += 1;
            }
        }
        
        // Step 2: Compute the prefix sum to get the net shifts for each character
        for (int i = 1; i < n; ++i) diff[i] += diff[i - 1]; // Add the value from the previous index

        for (int i = 0; i < s.size(); i++) {
            int shift = diff[i] % 26; // Calculate shifted character

            if (shift < 0)  shift += 26; // Handle negative shifts (backward)

            int value=(s[i] - 'a' + shift) % 26;
            s[i] = 'a' + value; // Map back to character
        }
        return s;
    }
};