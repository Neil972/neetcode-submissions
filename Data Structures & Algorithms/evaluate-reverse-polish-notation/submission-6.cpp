#include <unordered_set>

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> inp;
    unordered_set<string> sym1 = {"+", "-"};
    unordered_set<string> sym2 = {"*", "/"};

    for (string c : tokens) {
      // std::cout << "char" << c;
      if (sym1.find(c) == sym1.end() && sym2.find(c) == sym2.end()) {
        int inpVal = std::stoi(c);
        // std::cout << inpVal;
        inp.push(inpVal);
      } else {
        int res = ((sym1.find(c) != sym1.end()) ? 0 : 1);
        int topVal1 = inp.top();
        inp.pop();
        int topVal2 = inp.top();
        inp.pop();

        if (c == "+") {
          res = topVal2 + topVal1;
        } else if (c == "-") {
          res = topVal2 - topVal1;
        } else if (c == "*") {
          res = topVal2 * topVal1;
        } else if (c == "/") {
          res = topVal2 / topVal1;
        }

        inp.push(res);
      }
    }
    return inp.top();
  }
};
