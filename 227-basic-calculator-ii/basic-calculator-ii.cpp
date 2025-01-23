class Solution {
public:
    int calculate(string s) {
        char prevOp='+';
        int n=s.size();
        stack<int> st;
        int currVal=0;

        for(int i=0; i<n; i++){
            if(isdigit(s[i])) currVal=currVal*10 + (s[i]-'0');
            
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || i==n-1){ //i==n-1 for processing the
            //last value
                if(prevOp=='+') st.push(currVal);
                if(prevOp=='-') st.push(-currVal);
                if(prevOp=='*'){
                    int lastVal=st.top();
                    st.pop();
                    int newVal=lastVal*currVal;
                    st.push(newVal);
                }
                if(prevOp=='/'){
                    int lastVal=st.top();
                    st.pop();
                    int newVal=lastVal/currVal;
                    st.push(newVal);
                }
                currVal=0;
                prevOp=s[i];
            }
        }
        int result=0;
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        return result;
    }
};