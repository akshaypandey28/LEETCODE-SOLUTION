class Solution {
public:
    int mod=1e9+7;
    vector<int> nse(vector<int> &arr) {
        int n = arr.size();
        vector<int> output(n, n);
        stack<int> st; // storing indexes

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                output[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return output;
    }
    vector<int> psee(vector<int> &arr) {
        int n = arr.size();
        vector<int> output(n, -1);
        stack<int> st; // storing indexes

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                output[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        return output;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> next=nse(arr);
        vector<int> prev=psee(arr);
        int count=0;
        for(int i=0; i<arr.size(); i++){
            int left=i-prev[i];
            int right=next[i]-i;
            count=(count+ (left*right*1ll*arr[i])%mod)%mod;
        }
        return count;
    }
};