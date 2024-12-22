//Time => O(3^4)*O(N) 3 is at every call there will be 3 recursive call and 4 is height of the recursion
class Solution {
public:
    int n;
    vector<string> result;
    
    bool isValid(string str) {
        if(str[0] == '0') return false;
        
        int val = stoi(str);
        
        return val <= 255;
    }
    
    void solve(string& s, int idx, int part, string curr) {
        if(idx == n && part == 4) {
            curr.pop_back(); // to remove the extra last dot
            result.push_back(curr);
            return;
        }
        
        if(idx+1 <= n)  solve(s, idx+1, part+1, curr + s.substr(idx, 1) + ".");
        
        if(idx+2 <= n && isValid(s.substr(idx, 2))) {
            solve(s, idx+2, part+1, curr + s.substr(idx, 2) + ".");
        }
        
        if(idx+3 <= n && isValid(s.substr(idx, 3))) {
            solve(s, idx+3, part+1, curr + s.substr(idx, 3) + ".");
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        
        n = s.length();
        
        if(n > 12)  return result;
      
        int part = 0;
        string curr = "";
        
        solve(s, 0, part, curr);
        return result;
        
    }
};