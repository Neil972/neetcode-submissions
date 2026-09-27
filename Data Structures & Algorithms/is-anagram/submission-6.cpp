class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        std::map<char,int>tMap;
        std::map<char,int>sMap;
        for(char n:t){
            if(tMap.contains(n)){
                tMap[n]=tMap[n]+1;
            }
            else{
             tMap[n]=1  ; 
            }
        }
        std::cout<<"&&&&"<<std::endl;
        for(char c:s){
         if(sMap.contains(c)){
            sMap[c]++;
         }
         else {
            sMap[c]=1;
         }
        }


        for(char v:t){
            if(sMap[v]!=tMap[v]){
             return false;
            }
        }
        return true;
    } 
};
