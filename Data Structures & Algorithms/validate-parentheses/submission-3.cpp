#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0){
            return false;
        }
        std::unordered_map<
         char,
         char
        > symMap= {
          {'}','{'},
          {']','['},
          {')','('}
        };
        unordered_set<char> sym 
        = {
            '{','(','['
        };
        vector<char> st;

        for(char c:s){
         if(
            sym.find(c)
            !=sym.end()
         ){
            st.push_back(c);
         }
         else{
            if(st.size()==0){
              return false;
            }
            else if(
                symMap[c] ==
                st[st.size()-1]
            ){
                st.pop_back();
            }
            else{
                return false;
            }
         }
        }

        if(st.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
};
