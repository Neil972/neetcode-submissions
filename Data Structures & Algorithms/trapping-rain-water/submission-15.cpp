class Solution {
 public:
  int trap(vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int lMax = 0;
    int rMax = 0;
    int totalRain = 0;
    while (i < j) {
      if (height[i] < height[j]) {
        if (height[i] > lMax) {
          lMax = height[i];
        } else {
          totalRain = totalRain + (lMax - height[i]);
        }
        i++;
      } else {
        if (height[j] > rMax) {
          rMax = height[j];
        } else {
          totalRain = totalRain + (rMax - height[j]);
        }
        j--;
      }
    }

    return totalRain;
  }
};
