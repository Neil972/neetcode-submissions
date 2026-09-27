#include <unordered_map>

class TimeMap {
 public:
  unordered_map<string, vector<pair<int, string>>> kv;
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    if (kv.find(key) != kv.end()) {
      kv[key].push_back({timestamp, value});
    } else {
      kv.insert({key, {{timestamp, value}}

      });
    }
  }

  string get(string key, int timestamp) {
    if (kv.find(key) == kv.end()) {
      return "";
    }
    vector<pair<int, string>>* vlist = &kv[key];

    int s = 0;
    int e = vlist->size() - 1;

    pair<int, string> res = (*vlist)[s];

    if (res.first > timestamp) {
      return "";
    }
    while (s <= e) {
      int m = std::ceil(static_cast<double>((s + e) / 2));
      pair<int, string>* midVal = &kv[key][m];
      // std::cout<<res.first<<":"<<timestamp<<":"<<m<<"\n";
      if (midVal->first == timestamp) {
        res = *midVal;
        break;
      } else {
        if (midVal->first < timestamp) {
          res = *midVal;
          s = m + 1;
        } else {
          e = m - 1;
        }
      }
    }

    return res.second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
