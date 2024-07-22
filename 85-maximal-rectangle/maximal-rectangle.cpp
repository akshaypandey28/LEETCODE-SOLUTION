class Solution {
public:
    int histogram(vector<int>& heights) {
        stack<int> s;
        s.push(0);
        int ans=0;
        for(int i=1; i<heights.size(); i++){
            while(s.empty()!=1 and heights[i] < heights[s.top()]){
                int ele=heights[s.top()];
                int nsi=i;
                s.pop();
                int psi=(s.empty()) ? -1:s.top();
                ans=max(ans,ele*(nsi-psi-1)); // (nsi-1)-psi if there is no element in the stack then 
                //previous smaller index is -1
            }
            s.push(i);
        }
        while(s.empty()!=1){  //stack me kuch element bache honge
            int ele=heights[s.top()];
            int nsi=heights.size();
            s.pop();
            int psi=(s.empty())? -1 : s.top();
            ans=max(ans,ele*(nsi-psi-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> prefix(n, vector<int>(m, 0));

        for(int i=0; i<m; i++) prefix[0][i]=matrix[0][i]-'0';

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='0') prefix[i][j]=0;
                else prefix[i][j]=prefix[i-1][j]+1;
            }
        }

        int ans=0;
        for(int i=0; i<n; i++){
            ans=max(ans,histogram(prefix[i]));
        }
        return ans;
    }
};