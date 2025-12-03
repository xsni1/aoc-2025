#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream file("input");
  std::string line;
  int limit = 100;
  int cur = 50;
  int res = 0;

  while (std::getline(file, line) && line != "") {
    int firstNum = -1;
    int secondNum = -1;

    for (int i = 0; i < line.size(); i++) {
      int curNum = line[i] - 48;

      if (firstNum == -1) {
        firstNum = curNum;
        continue;
      }

      if (secondNum == -1) {
        secondNum = curNum;
        continue;
      }

      if (secondNum > firstNum) {
        firstNum = secondNum;
        secondNum = curNum;
        continue;
      }

      if (curNum > secondNum) {
        secondNum = curNum;
      }
    }

    res += (firstNum * 10) + secondNum;
  }

  std::cout << "Result: " << res << std::endl;
}
