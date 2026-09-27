class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size());
    stack<int> dist;

    for (int i = 0; i < temperatures.size(); i++) {
      while (dist.size() > 0 && temperatures[i] > temperatures[dist.top()]) {
        int ref = dist.top();
        res[ref] = i - ref;
        dist.pop();
      }
      dist.push(i);
    }

    return res;
  }
};

