

#include <utility>
class Solution {
 public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, int>> ps(speed.size());

    for (int i = 0; i < speed.size(); i++) {
      ps[i] = {position[i], speed[i]};
    }

    std::sort(ps.begin(), ps.end(),
              [](const pair<int, int>& a, const pair<int, int>& b) { return a.first < b.first; });

    vector<double> time;
    for (int k = 0; k < ps.size(); k++) {
      // std::cout<<ps[k].first<<"\n";
      time.push_back((double)(target - ps[k].first) / ps[k].second);
    }
    stack<double> res;

    for (int j = time.size() - 1; j > -1; j--) {
      // float time = (float)(target-ps[j].first)/ ps[j].second;
      if (res.size() == 0 || time[j] > res.top()) {
        // std::cout<<time[j]<<"\n";
        res.push(time[j]);
      }
    }

    return res.size();
  }
};