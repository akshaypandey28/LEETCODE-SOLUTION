class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
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
};