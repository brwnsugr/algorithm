class StockSpanner {
    vector<int> spans;
    vector<int> stocks;
public:
    StockSpanner(){}
    
    int next(int price) {
        int max_consecutive_days = 1;
        stocks.push_back(price);
        int idx = int(stocks.size())-1;
        if(idx == 0){
            spans.push_back(max_consecutive_days);
            return max_consecutive_days;
        }
        while(idx > 0){
            if(price < stocks[idx-1]) break;
            else{
                max_consecutive_days += spans[idx-1];
                idx -= spans[idx-1];
            }
        }
        spans.push_back(max_consecutive_days);
        return max_consecutive_days;
    }
};