#include <print>
#include <format>
class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    map<string, set<char>> records;
    bool res = true;
#define CHECK_SUDOKU(k, l)                                                \
  do {                                                                    \
    for (int i = 0; i < board.size(); i++) {                              \
      for (int j = 0; j < board[i].size(); j++) {                         \
        if (board[i][j] != '.') {                                         \
          string xregn = std::to_string((int)std::floor(i / k));          \
          string yregn = std::to_string((int)std::floor(j / l));          \
          string zone = xregn + yregn;                                    \
          if (records.find(zone) != records.end()) {                      \
            if (records[zone].find(board[i][j]) == records[zone].end()) { \
              records[zone].insert(board[i][j]);                          \
            } else {                                                      \
              res = false;                                                \
              break;                                                      \
            }                                                             \
          } else {                                                        \
            records.insert({zone, {board[i][j]}});                        \
          }                                                               \
        }                                                                 \
      }                                                                   \
      if (res == false) {                                                 \
        break;                                                            \
      }                                                                   \
    }                                                                     \
    records = {};                                                         \
    std::cout << "QWERTY=>" << 'k' << k << 'l' << l << res;               \
  } while (0)

    // bool isValid = true;
    CHECK_SUDOKU(3, 3);
    if (res == false) {
      return false;
    }
    CHECK_SUDOKU(9, 1);
    if (res == false) {
      return false;
    }
    CHECK_SUDOKU(1, 9);
    if (res == false) {
      return false;
    }

#undef CHECK_SUDOKU

    return true;
  }
};
