#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

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

  for (int i = 0; i < lines[0].size(); i++) {
    if (lines[0][i] == 'S') {
      beamsQueue.push_back(i);
      break;
    }
  }

  for (int i = level; i < lines.size() - 1; i++) {
    int size = beamsQueue.size();

    for (int j = 0; j < size; j++) {
      if (lines[i + 1][beamsQueue.front()] == '^') {
        res++;
        if (beamsMap.find(beamsQueue.front() - 1) == beamsMap.end()) {
          beamsQueue.push_back(beamsQueue.front() - 1);
          beamsMap[beamsQueue.front() - 1] = 1;
        }

        if (beamsMap.find(beamsQueue.front() + 1) == beamsMap.end()) {
          beamsQueue.push_back(beamsQueue.front() + 1);
          beamsMap[beamsQueue.front() + 1] = 1;
        }

        beamsMap.erase(beamsQueue.front());
        beamsQueue.pop_front();
      } else {
        beamsQueue.push_back(beamsQueue.front());
        beamsQueue.pop_front();
      }
    }
  }

  std::cout << "Result: " << res << std::endl;
}
