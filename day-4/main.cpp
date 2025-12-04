#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream file("input");
  std::string line;
  int res = 0;
  std::vector<std::string> lines;

  while (std::getline(file, line) && line != "") {
    lines.push_back(line);
  }

  int removed = 0;
  do {
    removed = 0;

    for (int i = 0; i < lines.size(); i++) {
      for (int j = 0; j < lines[i].size(); j++) {
        if (lines[i][j] != '@')
          continue;

        int count = 0;
        // upper left
        if (i != 0 && j != 0) {
          count += lines[i - 1][j - 1] == '@' ? 1 : 0;
        }

        // upper right
        if (i != 0 && j != lines[i].size() - 1) {
          count += lines[i - 1][j + 1] == '@' ? 1 : 0;
        }

        // lower left
        if (i != lines.size() - 1 && j != 0) {
          count += lines[i + 1][j - 1] == '@' ? 1 : 0;
        }

        // lower right
        if (i != lines.size() - 1 && j != lines[i].size() - 1) {
          count += lines[i + 1][j + 1] == '@' ? 1 : 0;
        }

        // upper
        if (i != 0) {
          count += lines[i - 1][j] == '@' ? 1 : 0;
        }

        // lower
        if (i != lines.size() - 1) {
          count += lines[i + 1][j] == '@' ? 1 : 0;
        }

        // right
        if (j != lines[i].size() - 1) {
          count += lines[i][j + 1] == '@' ? 1 : 0;
        }

        // left
        if (j != 0) {
          count += lines[i][j - 1] == '@' ? 1 : 0;
        }

        if (count < 4) {
          res++;
          removed++;
          lines[i][j] = '.';
          // res += count < 4 ? 1 : 0;
        }
      }
    }

  } while (removed > 0);

  std::cout << "Result: " << res << std::endl;
}
