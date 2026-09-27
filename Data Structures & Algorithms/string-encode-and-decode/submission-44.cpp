
class Solution {
 public:
  string encode(vector<string>& strs) {
    string encoded = "";

    for (string j : strs) {
      encoded = encoded + j + "*-qwert-*";
    }

    return encoded;
  }

  vector<string> decode(string s) {
    vector<string> resp;
    while (s.size() > 8) {
      int dlmitPosn = s.find("*-qwert-*");
      string data = s.substr(0, dlmitPosn);
      resp.push_back(data);
      s = s.substr(dlmitPosn + 8 + 1, s.size());
    }

    return resp;
  }
};