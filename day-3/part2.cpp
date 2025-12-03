#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream file("input");
  std::string line;
  long long res = 0;

  while (std::getline(file, line) && line != "") {
    std::vector<int> nums;

    for (int i = 0; i < line.size(); i++) {
      int curNum = line[i] - 48;

      if (nums.size() < 12) {
        nums.push_back(curNum);
        continue;
      }

      int idxToDelete = -1;
      for (int j = 0; j < nums.size() - 1; j++) {
        if (nums[j] < nums[j + 1]) {
          idxToDelete = j;
          break;
        }
      }

      if (idxToDelete == -1) {
        if (nums.back() < curNum) {
          nums.pop_back();
        } else {
          continue;
        }
      } else {
        nums.erase(nums.begin() + idxToDelete);
      }

      nums.push_back(curNum);
    }

    long long num = 0;
    for (auto &it : nums) {
      num *= 10;
      num += it;
    }
    res += num;
  }

  std::cout << "Result: " << res << std::endl;
}
