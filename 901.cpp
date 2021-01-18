class StockSpanner {
public:
    typedef pair<int, int> pi;
    stack<pi> thistack; 
    int currid; 
    
    StockSpanner() {
        currid = 0; 
    }
    
    int next(int price) {
        currid++; 
        if(thistack.empty()){
            thistack.push(make_pair(price, currid)); 
            return 1; 
        }
        else{
            while(1){
                if(thistack.empty()){
                    thistack.push(make_pair(price, currid)); 
                    return currid; 
                }
                pi currpair = thistack.top(); 
                if(currpair.first > price){
                    thistack.push(make_pair(price, currid)); 
                    return (currid - currpair.second); 
                }
                thistack.pop(); 
            }
            return -1; 
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
