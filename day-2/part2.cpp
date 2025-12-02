#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

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

        std::cout << "lo: " << low << " hi: " << hi << std::endl;
        for (long long i = low; i <= hi; i++) {
          int digits = std::ceil(std::log(i) / std::log(10));
          std::vector<int> divisors;
          for (int j = 1; j <= digits / 2; j++) {
            if (digits % j == 0)
              divisors.push_back(j);
          }

          for (const int &l : divisors) {
            long long cur = i;
            long long base = l == 1 ? 10 : std::pow(10, (digits / l));
            int prev = -1;
            bool correct = true;

            while (cur > 0) {
              int rem = cur % base;
              if (prev != -1 && rem != prev) {
                correct = false;
                break;
              }
              prev = rem;
              cur = cur / base;
            }

            if (correct) {
              std::cout << "correct: " << i << std::endl;
              res += i;
              break;
            }
          }
        }

      } else {
        number += line[i];
      }
    }
  }

  std::cout << "Result: " << res << std::endl;
}
