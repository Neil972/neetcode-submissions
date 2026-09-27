class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int ps = 0;
    int pe = matrix.size() - 1;

    int pm = std::floor((ps + pe) / 2);
    // std::cout<<pm<<"\n";
    while (ps <= pe) {
      if (matrix[pm][0] <= target && matrix[pm][matrix[pm].size() - 1] >= target) {
        break;
      } else if (matrix[pm][0] > target) {
        pe = pm - 1;
      } else {
        ps = pm + 1;
      }
      pm = std::floor((ps + pe) / 2);
      // std::cout<<pm<<":"<<ps<<":"<<pe<<"\n";
    }

    // std::cout<<pm<<"\n";
    int s = 0;
    int e = matrix[pm].size() - 1;

    int m = std::floor((s + e) / 2);
    int found = false;
    while (s <= e) {
      if (matrix[pm][m] == target) {
        found = true;
        break;
      } else if (matrix[pm][m] > target) {
        e = m - 1;
      } else {
        s = m + 1;
      }
      m = std::floor((s + e) / 2);
      std::cout << s << ":" << e << ":" << m << "\n";
    }

    return found;
  }
};
