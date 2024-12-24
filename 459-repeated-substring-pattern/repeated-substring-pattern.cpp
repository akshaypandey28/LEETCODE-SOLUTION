class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string copy=s+s;
        return copy.substr(1, copy.length()-2).find(s) != -1;
    }
};



/* 

T.C : O(n * sq_root(n))

1 => only for => if line maximum number of times it gets executed is equal to number of divisors of n which is equal to sq_root(n) => means 2*sq_root(n) no. of times gets executed if line

2 => and for each if line execution substr takes n and while loop executes for (times=n/l) times
so (n+n/l)~ n

so overall Time complexity is O(2*sq_root(n) * (n + n/l)) =>
T.C => O(sq_root(n) * n)

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        //You can also try from l = n/2 to l = 1 -> for(int l = n/2; l >= 0; l--) //This can be helpful for large test valid cases to return early
        for(int l = 1; l <= n/2; l++) {
            
            if(n%l == 0) { 
                int times = n/l;
                
                string pattern   = s.substr(0, l);
                string newStr = "";

                while(times--)  newStr += pattern;
                
                if(newStr == s)  return true;
            }
        }
        
        return false;
    }
};

 */