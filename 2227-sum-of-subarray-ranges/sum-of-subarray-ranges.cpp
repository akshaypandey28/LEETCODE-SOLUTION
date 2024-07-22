class Solution {
public:
    vector<int> nge(vector<int> &arr) {
        int n = arr.size();
        vector<int> output(n, n);
        stack<int> st; // storing indexes

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] > arr[st.top()]) {
                output[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return output;
    }

    // Function to find the previous greater or equal element
    vector<int> pgee(vector<int> &arr) {
        int n = arr.size();
        vector<int> output(n, -1);
        stack<int> st; // storing indexes

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] >= arr[st.top()]) {
                output[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return output;
    }
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
    long long subArrayRanges(vector<int>& arr) {
        vector<int> next_gre = nge(arr);
        vector<int> prev_gre = pgee(arr);
        long long count = 0;
        for (int i = 0; i < arr.size(); i++) {
            long long left = i - prev_gre[i];
            long long right = next_gre[i] - i;
            count = (count + (left * right * 1ll * arr[i])) ;
        }
        vector<int> next=nse(arr);
        vector<int> prev=psee(arr);
        
        for(int i=0; i<arr.size(); i++){
            int left=i-prev[i];
            int right=next[i]-i;
            count=(count- (left*right*1ll*arr[i]));
        }
        return count;
    }
};