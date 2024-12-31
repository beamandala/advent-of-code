#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

int p1(std::vector<int> *v1, std::vector<int> *v2);
int p2(std::vector<int> *v1, std::vector<int> *v2);

int main() {
  std::vector<int> v1, v2;
  std::ifstream istrm("input.txt", std::ios::binary);

  if (!istrm.is_open()) {
    std::cerr << "Failed to open input file\n";

    return 1;
  } else {
    int n1, n2;

    while (istrm >> n1 >> n2) {
      v1.push_back(n1);
      v2.push_back(n2);
    }

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
  }

  int distance = p1(&v1, &v2);
  std::cout << "Total distance: " << distance << "\n";

  int similarity_score = p2(&v1, &v2);
  std::cout << "Similarity score: " << similarity_score << "\n";

  return 0;
}

int p1(std::vector<int> *v1, std::vector<int> *v2) {
  int distance = 0;

  for (size_t i = 0; i < (*v1).size(); i++) {
    distance += abs((*v1)[i] - (*v2)[i]);
  }

  return distance;
}

int p2(std::vector<int> *v1, std::vector<int> *v2) {
  int similarity_score = 0;

  for (size_t i = 0; i < v1->size(); i++) {
    similarity_score += (*v1)[i] * std::count(v2->begin(), v2->end(), (*v1)[i]);
  }

  return similarity_score;
}
