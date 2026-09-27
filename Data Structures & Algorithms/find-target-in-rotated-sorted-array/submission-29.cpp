class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int s = 0;
    int e = nums.size() - 1;
    int res = -1;
    while (s <= e) {
      int m = std::floor(
        (s + e) / 2
      );
      std::cout<<s<<":"<<
      e<<":"<<m<<"\n";
      if (nums[m] == target) {
        res = m;
        break;
      } else if (
        nums[s] <= nums[m]
     ) {
        if (
          target < nums[m] &&
          target >= nums[s]
        ) {
          e = m - 1;
        } else {
          s = m + 1;
        }
      } else {
        if (
          target > nums[m] &&
          target <= nums[e]
        ) {
          s = m + 1;
        } else {
          e = m - 1;
        }
      }
    }

    return res;
  }
};
