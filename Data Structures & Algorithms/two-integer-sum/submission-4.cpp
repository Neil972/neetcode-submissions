class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        return twoPtr(0,1,target,nums);
    }
      vector<int> twoPtr(int i,int j, int sum,vector<int>& inp){
       if(i==j) return {0,1};
       if(inp[i]+inp[j]==sum){
        return {i,j};
       }
       else if(j==inp.size()-1){
        return twoPtr(1+i,2+i,sum,inp);
       }
       else{
        return twoPtr(i,1+j,sum,inp);
       }
      }

    
    
};
