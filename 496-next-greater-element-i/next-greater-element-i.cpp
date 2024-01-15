class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int,int> m;
        st.push(0); //indexing for nums2
        for(int i=1; i<nums2.size(); i++){
            while(st.empty()!=1 and nums2[i] > nums2[st.top()]){
                //nums2[st.top()]=nums2[i];
                m[nums2[st.top()]]=nums2[i];
                st.pop();
            }
            st.push(i);
        }
        while(st.empty()!=1){
            m[nums2[st.top()]]=-1;
            st.pop();
        }
        for(int i=0; i<nums1.size(); i++){
            if(m.count(nums1[i])==1) nums1[i]=m[nums1[i]];
        }
        return nums1;
    }
};