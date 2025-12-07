#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::ifstream file("input");
  std::string line;
  std::vector<std::vector<std::string>> lines;
  long long res = 0;

  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string cur;
    std::vector<std::string> line;

    while (ss >> cur) {
      line.push_back(cur);
    }

    lines.push_back(line);
  }

  for (int j = 0; j < lines[0].size(); j++) {
    long long localRes = 0;
    std::string sign = lines[lines.size() - 1][j];
    if (sign == "*")
      localRes = 1;

    for (int i = 0; i < lines.size() - 1; i++) {
      if (sign == "+") {
        localRes += stoi(lines[i][j]);
      } else {
        localRes *= stoi(lines[i][j]);
      }
    }

    res += localRes;
  }

  std::cout << "Result: " << res << std::endl;
}
