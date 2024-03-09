class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        int i=0,j=0;
        while(i<nums1.size() and j<nums2.size()){
            if(nums1[i]<nums2[j]){
                a.push_back(nums1[i]);
                i++;
            }
            else{
                a.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            a.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            a.push_back(nums2[j]);
            j++;
        }
        for(int k=0; k<a.size(); k++) cout<<a[k]<<" ";
        int n=a.size()/2;
        if(a.size()%2==1){
            double x=(double)a[n];
            return x;
        }
        else {
            double x=(double)a[n];
            double y=(double)a[n-1];
            return (x+y)/2;
        }
    }
};