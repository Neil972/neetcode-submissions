class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0;
    int j = numbers.size() - 1;

    // numbers[i]
    //+numbers[j];
    vector<int> resp;
    while (true) {
      if (i > j || i == numbers.size() || j == 0) {
        break;
      }
      // std::cout << "i:" << i << "j:" << j << "\n";
      int sum = numbers[i] + numbers[j];
      if (sum == target) {
        resp.push_back(1 + i);
        resp.push_back(1 + j);
        break;
      } else if (sum < target) {
        i++;
      } else {
        j--;
      }
    }

    return resp;
  }
};

