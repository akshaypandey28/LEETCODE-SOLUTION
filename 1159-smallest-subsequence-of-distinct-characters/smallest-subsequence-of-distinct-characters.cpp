//316. Remove Duplicate Letters

//Approach-1 (Using string as a stack)
//T.C : O(n) - We visit each character only once (Note that an element once popped from result is never put back)
//S.C : O(1)
class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        string result;
        
        vector<bool> taken(26, false); //O(1) space
        vector<int> lastIndex(26); //O(1) space
        
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            lastIndex[ch-'a'] = i;
        }
        
        
        for(int i = 0; i < n; i++) {
            
            int idx = s[i] - 'a';
            
            if(taken[idx] == true) continue;
            
            while(result.length() > 0 && s[i] < result.back() && lastIndex[result.back() - 'a'] > i) {
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            result.push_back(s[i]);
            taken[idx] = true;
            
        }
        
        return result;
    }
};
/* 
//Approach-2 (Using stack)
//T.C : O(n) - We visit each character only once (Note that an element once popped from result is never put back)
//S.C : O(n) stack
class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        stack<char> st;
        
        vector<bool> taken(26, false);
        vector<int> lastIndex(26);
        
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            
            lastIndex[ch-'a'] = i;
        }
        
        
        for(int i = 0; i < n; i++) {
            
            int idx = s[i] - 'a';
            
            if(taken[idx] == true) continue;
            
            while(!st.empty()  && s[i] < st.top() && lastIndex[st.top() - 'a'] > i) {
                taken[st.top() - 'a'] = false;
                st.pop();
            }
            
            st.push(s[i]);
            taken[idx] = true;
            
        }
        
        string result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        reverse(begin(result), end(result));
        
        return result;
    }
};
 */