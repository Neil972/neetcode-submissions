class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);

    int t = nums1.size() + nums2.size();
    int half = (t + 1) / 2;

    int s = 0;
    int e = nums1.size();

    double median = 0.0;
    while (s <= e) {
      int m1 = (s + e) / 2;
      int m2 = half - m1;

      int aLeft = m1 == 0 ? INT_MIN : nums1[m1 - 1];
      int aRight = m1 == nums1.size() ? INT_MAX : nums1[m1];
      int bLeft = m2 == 0 ? INT_MIN : nums2[m2 - 1];
      int bRight = m2 == nums2.size() ? INT_MAX : nums2[m2];

      if (aLeft <= bRight && bLeft <= aRight) {
        if (t % 2 == 1) {
          median = static_cast<double>(std::max(aLeft, bLeft));
        } else {
          median = static_cast<double>(std::max(aLeft, bLeft) + std::min(aRight, bRight)) / 2;
        }
        break;
      } else {
        if (aLeft > bRight) {
          e = m1 - 1;
        } else {
          s = m1 + 1;
        }
      }
    }
    return median;
  }
};