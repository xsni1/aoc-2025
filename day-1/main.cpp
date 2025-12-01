#include <fstream>
#include <iostream>

int main() {
  std::ifstream file("input");
  std::string line;
  int limit = 100;
  int cur = 50;
  int res = 0;

  while (std::getline(file, line) && line != "") {
    bool direction = line[0] == 'L' ? false : true;
    int step = stoi(line.substr(1, line.size() - 1));
    bool isZero = cur == 0 ? true : false;

    cur += direction ? (step) : (step * -1);
    if (cur <= 0)
      res += (!isZero ? 1 : 0) + (cur / 100 * -1);
    if (cur >= 100)
      res += cur / 100;

    cur = cur % limit;
    if (cur < 0)
      cur = limit + cur;
  }

  std::cout << "Result: " << res << std::endl;
}
