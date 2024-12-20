class Solution {
public:
    vector<int>    val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; //size is 13
    vector<string> sym{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string intToRoman(int num) {
        string ans="";
        for(int i=0; i<13; i++){
            if(num==0) break;
            int times=num/val[i];

            while(times--)  ans=ans+sym[i]; 

            num=num%val[i];
        }
        return ans;
    }
};

/* 
class Solution {
public:
    void make(string &ans,char major,char middle,char minor,int val){//major=X,middle=V,minor=I and so on further
        if(val<=3){
            for(int i=1; i<=val; i++) ans.push_back(minor);
        }
        else if(val==4){
            ans.push_back(minor);
            ans.push_back(middle);
        }
        else if(val==5) ans.push_back(middle);
        else if(val<=8){
            ans.push_back(middle);
            for(int i=6; i<=val; i++) ans.push_back(minor);
        }
        else if(val==9){
            ans.push_back(minor);
            ans.push_back(major);
        }
        //else ans.push_back(major); for 10 but there is no use of this line in the code
    }
    string intToRoman(int num) {
        string ans="";
        make(ans,'*','*','M',num/1000); //there is no value for 10000 and 5000 so there is no middle and major for value <=3999
        num=num%1000;
        make(ans,'M','D','C',num/100);
        num=num%100;
        make(ans,'C','L','X',num/10);
        num=num%10;
        make(ans,'X','V','I',num);
        return ans;
    }
};
 */