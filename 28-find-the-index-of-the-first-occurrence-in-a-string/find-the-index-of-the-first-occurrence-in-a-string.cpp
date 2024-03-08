class Solution {
public:
    int strStr(string haystack, string needle) {
        // if(haystack.find(needle)!=-1) {
        //     int idx=haystack.find(needle);
        //     return idx;
        // }
        // else return -1;
        return haystack.find(needle);
    }
};