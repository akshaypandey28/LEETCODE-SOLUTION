class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        //longest common prefix
        int x = s1.size();
        int y = s2.size();
        int z = s3.size();
        int n=min({x,y,z});
       
        int count=0;
        if( s1[0]!=s2[0] || s2[0]!= s3[0] || s1[0]!=s3[0] ) return -1;
        for(int i =0;i<n;i++){
           if( s1[i]==s2[i] && s2[i]==s3[i] ) count++;
           else break;
        }
        return ((x+y+z) -(3*count));
    }
};