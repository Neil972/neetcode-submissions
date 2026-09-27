class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mp = 0;

        for(int p:piles){
            mp=std::max(mp,p);
        }

        int s=1;
        int e=mp;
        int res=mp;
        while(s<=e){
         int k = std::ceil(
            (s+e)/2
         );
         
         int ch =0;

         for(int j:piles){
            ch = ch+
            std::ceil(
             static_cast<
              double
             >(j)/k
            );
         }

         if(ch<=h){
            res=k;
            std::cout
            <<ch
            <<":"
            <<h
            <<":"
            <<k
            <<"\n";
            e=k-1;
         }
         else{
           s=k+1;
         }


        }

        return res;
    }
};
