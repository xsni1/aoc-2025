#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool comp(std::vector<long long> a, std::vector<long long> b) {
  return a[0] < b[0];
}

int main() {
  std::ifstream file("input");
  std::string line;
  std::vector<std::vector<long long>> ranges;
  std::vector<std::vector<long long>> mergedRanges;
  long long res = 0;

  while (std::getline(file, line) && line != "") {
    int delimiter = line.find('-');
    std::vector<long long> range;
    range.push_back(stoll(line.substr(0, delimiter)));
    range.push_back(stoll(line.substr(delimiter + 1, line.size() - delimiter)));
    ranges.push_back(range);
  }

  std::sort(ranges.begin(), ranges.end(), comp);

  long long prevStart = ranges[0][0], prevEnd = ranges[0][1];
  for (int i = 1; i < ranges.size(); i++) {
    if (ranges[i][0] > prevEnd) {
      mergedRanges.push_back(std::vector<long long>{prevStart, prevEnd});
      prevStart = ranges[i][0];
      prevEnd = ranges[i][1];
      continue;
    }

    if (ranges[i][0] <= prevEnd) {
      prevEnd = ranges[i][1] > prevEnd ? ranges[i][1] : prevEnd;
    }
  }
  mergedRanges.push_back(std::vector<long long>{prevStart, prevEnd});

  for (auto it : mergedRanges) {
    res += it[1] - it[0] + 1;
  }

  std::cout << "Result: " << res << std::endl;
}
