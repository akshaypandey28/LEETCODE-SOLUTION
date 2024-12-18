class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> m;
        for(int i=0; i<s.size(); i++) m[s[i]]++;
        string result="";
        priority_queue<pair<char,int> >pq;

        for(auto p:m) pq.push(p); //here p acts a pair which stores map element in the form of pair in pq
            while(pq.empty()!=1){
                auto largest =pq.top(); //largest is in the form of pair
                pq.pop();
                int len=min(repeatLimit,largest.second);

                for(int i=0; i<len; i++)   result+=largest.first;

                pair<char,int> second_largest;
                if(largest.second-len > 0){
                    if(pq.empty()!=1){
                       second_largest=pq.top();
                       pq.pop();
                       result+=second_largest.first;
                    }
                    else  return result;

                    if(second_largest.second-1 > 0) pq.push( { second_largest.first , second_largest.second-1 } );

                    pq.push( { largest.first,largest.second-len } );
                }
            }
        return result;
    }
};