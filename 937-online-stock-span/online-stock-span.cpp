class StockSpanner {
public:
    stack<pair<int,int> > st; //value and it's span
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans=0;
        while(st.empty()!=1 and st.top().first<=price){
            ans+=st.top().second;
            st.pop();
        }
        st.push({price,ans+1});
        return ans+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */