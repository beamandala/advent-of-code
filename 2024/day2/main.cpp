#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int p1(std::vector<std::vector<int>> &reports);

int main() {
  std::ifstream file("input.txt");
  if (!file) {
    std::cerr << "Failed to open file.\n";
    return 1;
  }

  std::vector<std::vector<int>> reports;
  std::string line;

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::vector<int> levels;
    int value;

    while (iss >> value)
      levels.push_back(value);

    reports.push_back(levels);
  }

  std::cout << "Safe Reports: " << p1(reports) << "\n";

  return 0;
}

int p1(std::vector<std::vector<int>> &reports) {
  int safe_reports = 0;
  for (auto levels : reports) {
    int prev = levels[0];
    bool inc_initialized = false;
    bool inc = false;
    bool is_safe = true;

    for (size_t i = 1; i < levels.size(); ++i) {
      int diff = levels[i] - prev;

      if (abs(diff) < 1 || abs(diff) > 3) {
        is_safe = false;
        break;
      }

      if (!inc_initialized) {
        inc = diff > 0;
        inc_initialized = true;
      }

      if ((inc && diff < 0) || (!inc && diff > 0)) {
        is_safe = false;
        break;
      }

      prev = levels[i];
    }

    if (is_safe) {
      safe_reports++;
    }
  }
  return safe_reports;
}
