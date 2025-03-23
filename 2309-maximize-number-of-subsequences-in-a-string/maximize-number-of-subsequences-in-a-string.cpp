class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int count1=0;
        int count2=0;
        for(int i=0; i<text.size(); i++){
            if(text[i]==pattern[0]) count1++;
            if(text[i]==pattern[1]) count2++;
        }
        long long ans=0;
        if(count1>=count2) text+=pattern[1];
        else text.insert(text.begin(),pattern[0]);
        //i want to check no of subsequences end at pattern[1] character in text
        //by the help of prefix sum
        int pref=0;
        for(char ch:text){  
            if(ch==pattern[1]) ans+=pref;
            if(ch==pattern[0]) pref++;
        }
        return ans;
    }
};