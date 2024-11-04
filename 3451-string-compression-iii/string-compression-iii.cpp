class Solution {
public:
    string compressedString(string word) {
        string ans="";
        char ch=word[0];
        int count=1;
        for(int i=1; i<word.size(); i++){
            if(ch==word[i] and count<9) {
                count++;
            }
            else{
                ans.push_back(count+'0');
                ans.push_back(ch);
                ch=word[i];
                count=1;
            }
        }
        ans.push_back(count+48);
        ans.push_back(ch);
        return ans;
    }
};