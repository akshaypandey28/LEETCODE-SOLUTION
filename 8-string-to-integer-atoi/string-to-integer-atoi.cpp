class Solution {
public:
    int myAtoi(string s) {
        if(s.size()==0) return 0;
        long ans=0;
        bool neg=false;
        int i=0;
        while(i<s.size() and s[i]==' ') i++;
        s=s.substr(i); //i to the last of string
        if(s[0]=='-') neg=true;
        if(s[0]=='+' || s[0]=='-') i=1;
        else i=0;

        while(i < s.size() ){
            if(s[i]==' ' || !isdigit(s[i])) break;
            long dig=s[i]-'0';
            ans=ans*10 + dig;
            if(neg==true and -1*ans < INT_MIN) return INT_MIN;
            if(neg==false and ans>INT_MAX) return INT_MAX;
            i++;
        }
        if(neg==true) ans=ans*-1;
        return (int)ans;
    }
};