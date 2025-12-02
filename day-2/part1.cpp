#include <cmath>
#include <fstream>
#include <iostream>

int main() {
  std::ifstream file("input");
  std::string line;
  long long res = 0;

  while (std::getline(file, line) && line != "") {
    std::string number;
    long long low, hi;

    for (int i = 0; i < line.length(); i++) {
      if (line[i] == '-') {
        low = stoll(number);
        number = "";
      } else if (line[i] == ',' || i == line.length() - 1) {
        hi = stoll(number);
        number = "";

        for (long long i = low; i <= hi; i++) {
          int digits = std::ceil(std::log(i) / std::log(10));
          if (digits % 2 != 0)
            continue;
          long long base = std::pow(10, (digits / 2));
          if (i / base == i % base) {
            res += i;
          }
        }

      } else {
        number += line[i];
      }
    }
  }

  std::cout << "Result: " << res << std::endl;
}
