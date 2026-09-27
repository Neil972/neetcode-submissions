class Solution {
public:
    int maxProfit(
        vector<int>& prices
    ) {
        int s=0;
        int e=s+1;
        
        int maxProfit = 0;
        while(
            s<e && 
            e<prices.size()
        ){
          int profit =
           prices[e]-prices[s];
           if(profit <0){
            s=e;
            e=e+1;
           }
           else{
            maxProfit=std::max(
             maxProfit,
             profit 
            );
            e=e+1;
           }
        }
        return maxProfit;
    }
};
