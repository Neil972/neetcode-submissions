#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        vector<int> resp ;
        
        for(char c:s){
            if(
              std::isalnum(c)
               && 
              !std::isspace(c)
            ){
             resp.push_back(
              std::tolower(c)
             );
            }
            else{    
            //std::cout<<c<<"\n";
            }
        }

        int isPalindron=true;

        int i=0;
        int j=resp.size()-1;
        

        while(i<j){
            if(
                resp[i]
                !=resp[j]
            ){
               isPalindron 
               = false;
               break;
            }
            i++;
            j--;
        }

        return isPalindron;

        
    }
};
