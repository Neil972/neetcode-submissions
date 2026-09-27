class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> cis;

        for(int i:nums){
            cis.insert(i);
        }
        
        int ls=0;
        for(int j:cis){
            int seq=1;
            int nextj=1+j;
            if(
                cis.find(-1+j)
                ==cis.end()
            ){
             while(
                cis.find(nextj)
                !=cis.end()
             ){
               seq++;
               nextj++;
               //std::cout<<seq;
             }
             ls=std::max(
                ls, 
                seq
             );
            }
        }

        return ls;
    }
};
