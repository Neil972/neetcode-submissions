#include<map>
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      map<int,int>  fMap;

      for(int val:nums){
        if(fMap.contains(val)){
            fMap[val]++;
        }
        else{
            fMap[val]=0;
        }
      }
      
      vector<pair<int,int>> resp1 ;
      for(const auto& [key,val]:fMap){
       resp1.push_back({key,val});
      }

      std::sort(resp1.begin(),resp1.end(),comparator);
       
      vector<int> result  ;
      
      for(int b=0;b<k;b++){
        std::cout << resp1[b].first ;
        result.push_back(resp1[b].first);
      }
      
      return result ;

    }

    static bool comparator(
      pair<int,int> a,
      pair<int,int> b
    ){
      if(a.second>b.second) return true;
      else return false;
    }

    
};
