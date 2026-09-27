#include <algorithm>

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> resp;

    for (int r = 0; r < nums.size(); r++) {
      // if (r > 0 && nums[r] == nums[r - 1]) {
      // continue;
      // }

      int target = -1 * nums[r];
      // std::cout << target << "\n";
      int p = 0;
      int q = nums.size() - 1;

      while (p < q) {
        if ((nums[p] + nums[q]) > target) {
          q--;
        } else if ((nums[p] + nums[q]) < target) {
          p++;
        } else {
          if (r != q && p != r && p != q) {
            resp.push_back({nums[p], nums[q], nums[r]});

            if (p < q && nums[p] == nums[1 + p]) {
              while (p < q && nums[p] == nums[1 + p]) {
                p++;
              }
            }
            if (nums[q] == nums[-1 + q] && p < q) {
              while (nums[q] == nums[-1 + q] && p < q) {
                q--;
              }
            }
          }
          p++;
          q--;
        }
      }
    }
    set<vector<int>> respSet;
    for (vector<int> v : resp) {
    std:
      sort(v.begin(), v.end());
      respSet.insert(v);
    }

    return {respSet.begin(), respSet.end()};
  }
};
