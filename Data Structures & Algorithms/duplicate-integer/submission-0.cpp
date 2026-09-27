#include <set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> dT ={};
        for(int i = 0;i<nums.size();i++){
          if(dT.find(nums[i])==dT.end()){
            dT.insert(nums[i]);
          }
          else{
            return true;
          }
        }
        return false;
    }
};