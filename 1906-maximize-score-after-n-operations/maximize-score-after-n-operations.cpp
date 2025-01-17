//pick and not pick=> O(2^n)
//two loops => O(n^2)
//__gcd => euclidean algorithm log(max(a,b))
//T.C => O(2^n * n^2 * log(m))
//Approach-2 (Memoizing Approach-1 above)
class Solution {
public:
    int n;
    int solve(vector<int>&nums, vector<bool>&visited, int operation, unordered_map<vector<bool>, int>& mp) { 
        
        if(mp.find(visited) != mp.end())
            return mp[visited];
        
        int maxScore = 0;
        
        for (int i = 0; i < n - 1; i++) {
            if (visited[i])
                continue;
            
            for (int j = i + 1; j < n; j++) {
                if (visited[j])
                    continue;
                
                visited[i] = true;
                visited[j] = true;
                
                int currScore      = operation * __gcd(nums[i], nums[j]);
                int remainingScore = solve(nums, visited, operation + 1, mp);
                maxScore           = max(maxScore, currScore + remainingScore);
                
                visited[i] = false;
                visited[j] = false;
            }
        }
        
        return mp[visited] = maxScore;
    }
    int maxScore(vector<int>& nums) {
        n = nums.size();
        
        vector<bool>visited(n, false);
        
        unordered_map<vector<bool>, int> mp;
        
        int ans = solve(nums, visited, 1, mp);
        
        return ans;
        
    }
};

/* 
using maxScore as global variable

class Solution {
public:
    int n;
    int maxScoreGlobal; // Global variable to track the maximum score

    void solve(vector<int>& nums, vector<bool>& visited, int operation, int currentScore) { 
        // Base case: If all pairs are used, update the global maximum score
        if (operation > n / 2) {
            maxScoreGlobal = max(maxScoreGlobal, currentScore);
            return;
        }

        for (int i = 0; i < n - 1; i++) {
            if (visited[i]) continue;

            for (int j = i + 1; j < n; j++) {
                if (visited[j]) continue;

                // Pick the current pair
                visited[i] = true; 
                visited[j] = true;

                int currScore = operation * __gcd(nums[i], nums[j]);
                solve(nums, visited, operation + 1, currentScore + currScore);

                // Backtrack (unpick the current pair)
                visited[i] = false;
                visited[j] = false;
            }
        }
    }

    int maxScore(vector<int>& nums) {
        n = nums.size();
        maxScoreGlobal = 0; // Initialize the global maxScore variable
        
        vector<bool> visited(n, false);
        solve(nums, visited, 1, 0);

        return maxScoreGlobal; // Return the global maximum score
    }
};

 */


 /* 
 //Approach-1 (Recusion Brute Force Backtracking) - Using boolean visited array
class Solution {
public:
    int n;
    int solve(vector<int>&nums, vector<bool>&visited, int operation) { 
        
        int maxScore = 0;
        
        for (int i = 0; i < n - 1; i++) {
            if (visited[i]) continue;
            
            for (int j = i + 1; j < n; j++) {
                if (visited[j]) continue;
                
                //pick
                visited[i] = true; 
                visited[j] = true;
                
                int currScore      = operation * __gcd(nums[i], nums[j]);
                int remainingScore = solve(nums, visited, operation + 1);
                maxScore           = max(maxScore, currScore + remainingScore);
                
                //not pick
                visited[i] = false;
                visited[j] = false;
            }
        }
        
        return maxScore;
    }
    int maxScore(vector<int>& nums) {
        n = nums.size();
        
        vector<bool>visited(n, false);
        
        int ans = solve(nums, visited, 1);
        
        return ans;
        
    }
};

  */