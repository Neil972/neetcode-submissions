
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> angmap;

        for(string val:strs){
            string key=val;
            sort(key.begin(),key.end());
            if(angmap.contains(key)){
                angmap[key].push_back(val);
            }
            else{
                angmap[key]={val};
            }
        }

        vector<vector<string>> res;
        for(const auto & [key,val]:angmap){
          res.push_back(val);
        }
        return res;
    }
};
