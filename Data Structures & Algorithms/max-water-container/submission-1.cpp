class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;

        int j 
        = heights.size()-1;
        
        int area = 0;
        while(i<j){
        
        //std::cout<<"i"<<i
        //<<"j"<<j<<"\n";

         int height = 
         std::min(
            heights[i],
            heights[j]
         );
         
         int width = j-i;
         
         area = std::max(
            area,
            height*width 
         );

         if(
            heights[j]
            <heights[i]
         ){
            j--;
         }
         else{
            i++;
         }
         
        }

        return area;
    }
};
