#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream file("input");
  std::string line;
  std::vector<std::string> lines;
  long long res = 0;

  while (std::getline(file, line)) {
    lines.push_back(line);
  }

  long long curNum = 0;
  long long curRes = 0;
  char sign;
  for (int column = 0; column < lines[0].size(); column++) {
    bool empty = true;
    for (int row = 0; row < lines.size(); row++) {

      if (lines[row][column] != ' ')
        empty = false;

      if (row == lines.size() - 1 && !empty) {
        if (lines[row][column] == '*') {
          sign = '*';
        }

        if (lines[row][column] == '+') {
          sign = '+';
        }

        if (sign == '+') {
          curRes += curNum;
        } else if (sign == '*') {
          if (curRes == 0) {
            curRes = curNum;
          } else {
            curRes *= curNum;
          }
        }

        curNum = 0;
        continue;
      }

      if (lines[row][column] >= 48 && lines[row][column] <= 57) {
        curNum = (curNum * 10) + (lines[row][column] - 48);
        // std::cout << "cur num: " << curNum << std::endl;
      }
      std::cout << "col: " << column << " row: " << row << std::endl;
      std::cout << "cur num: " << curNum << std::endl;
      std::cout << "cur res: " << curRes << std::endl;
      std::cout << "sign: " << sign << std::endl;
      std::cout << "res: " << res << std::endl;
    }

    if (empty) {
      std::cout << "empty detected: " << column << std::endl;
      // /1k/ std::cout << "adding curRes: " << curRes << std::endl;
      res += curRes;
      curRes = 0;
      curNum = 0;
    }
  }

  std::cout << "Result: " << res + curRes << std::endl;
}
