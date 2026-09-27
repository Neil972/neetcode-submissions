class Solution {
public:
    int findMin(vector<int> &nums) {
        int s=0;
        int e =nums.size()-1;
        int res=nums[0];
        while(s<=e){
            int m=
            std::floor(
                (s+e)/2
            );
            std::cout
            <<m<<":"
            <<nums[m]<<"\n";
            res=std::min(
                res,
                nums[m]
            );

            if(
             nums[m]
             >nums[e]
            ){
                s=m+1;
            }
            else{
                e=m-1;
            }
        }

        return res;
    }
};
