class Solution {
public:
    string addStrings(string num1, string num2) {
        
        // Ensure num1 is the longer string
        if (num1.size() < num2.size()) swap(num1, num2);
        int n = num1.size();
        int m = num2.size();

        //adding leading zeros which has shorter length
        while(m<n){
            num2='0'+num2;
            m++;
        }
        string ans="";
        int i=n-1;
        int quotient=0;
        while(i>=0){
            int val=(num1[i]-'0') + (num2[i]-'0') + quotient;
            int rem=val%10;
            quotient=val/10;
            ans=char(rem+'0')+ans;
            i--;
        }

        if (quotient > 0)  ans = char(quotient + '0') + ans;
        
        return ans;
    }
};