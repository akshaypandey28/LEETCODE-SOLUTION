#define pp pair <int,pair<int,int> > //pair is index of nums1 and nums2
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
         priority_queue<pp,vector<pp>,greater<pp> > pq;
         for(int i=0; i<nums1.size(); i++){
             pq.push({nums1[i]+nums2[0] , {i,0}});
         }
         pp ans;//variable
         vector<vector<int>> result;
         while(k-- and pq.empty()!=1){
             ans=pq.top();
             pq.pop();
             int sum=ans.first;
             int nums1_idx=ans.second.first;
             int nums2_idx=ans.second.second;
             result.push_back({nums1[nums1_idx],nums2[nums2_idx]});
             if( (nums2_idx+1) < nums2.size() ){
                 pq.push({nums1[nums1_idx] + nums2[nums2_idx+1] , {nums1_idx,nums2_idx+1}});
             }
         }
         return result;
    }
};