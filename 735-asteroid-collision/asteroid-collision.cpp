class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> s;

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) s.push(asteroids[i]);
            else {
                // Handle collisions with negative asteroid
                while (!s.empty() && s.top() >=1 && s.top() < -asteroids[i])  s.pop();

                if (!s.empty() && s.top() == -asteroids[i]) s.pop();
                else if (s.empty() || s.top() < 0) s.push(asteroids[i]);
            }
        }

        // Transfer elements from stack to result vector
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        // Reverse to correct the order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
