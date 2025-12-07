#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<int, std::unordered_map<int, long long>> cache;

long long count_paths(std::vector<std::string> lines, int x, int y) {
  if (y < lines.size() && (x < 0 || x >= lines[y].size())) {
    return 0;
  }

  if (y >= lines.size()) {
    return 1;
  }

  if (auto itx = cache.find(x);
      itx != cache.end() && itx->second.find(y) != itx->second.end()) {
    return itx->second[y];
  }

  long long res = 0;
  if (lines[y][x] == '^') {
    res = count_paths(lines, x + 1, y + 1) + count_paths(lines, x - 1, y + 1);
  } else {
    res = count_paths(lines, x, y + 1);
  }

  cache[x][y] = res;

  return res;
}

int main() {
  std::ifstream file("input");
  std::vector<std::string> lines;
  std::string line;
  std::deque<int> beamsQueue;
  std::unordered_map<int, int> beamsMap;
  int level = 1;
  int res = 0;

  while (std::getline(file, line) && line != "") {
    lines.push_back(line);
  }

  int x = 0;
  for (int i = 0; i < lines[0].size(); i++) {
    if (lines[0][i] == 'S') {
      x = i;
      break;
    }
  }

  std::cout << "Result: " << count_paths(lines, x, 1) << std::endl;
}
